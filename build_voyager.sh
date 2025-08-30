#!/usr/bin/env bash
# build_voyager.sh — macOS, Docker-based local build for ZSA/QMK

set -euo pipefail

LAYOUT_ID="BRyqO"
GEOMETRY="voyager"
QMK_DIR=""
OUT_DIR="dist"
KEEP_TMP=0
DOCKER_IMAGE="qmkfm/qmk_cli:latest"

die() {
  echo "✖︎ $*" >&2
  exit 1
}
have() { command -v "$1" >/dev/null 2>&1; }

print_help() {
  cat <<EOF
Usage:
  $0 -l <LAYOUT_ID> [-g <GEOMETRY>] [-q <QMK_DIR>] [-o <OUT_DIR>] [--keep-tmp]
Examples:
  $0 -l BRyqO -g voyager
  $0 -l BRyqO -g ergodox_ez/stm32 --keep-tmp
EOF
}

while [[ $# -gt 0 ]]; do
  case "$1" in
  -l | --layout)
    LAYOUT_ID="${2:?}"
    shift 2
    ;;
  -g | --geometry)
    GEOMETRY="${2:?}"
    shift 2
    ;;
  -q | --qmk-dir)
    QMK_DIR="${2:?}"
    shift 2
    ;;
  -o | --out-dir)
    OUT_DIR="${2:?}"
    shift 2
    ;;
  --keep-tmp)
    KEEP_TMP=1
    shift
    ;;
  -h | --help)
    print_help
    exit 0
    ;;
  *) die "Unknown argument: $1" ;;
  esac
done

for dep in docker git curl unzip jq; do have "$dep" || die "Missing dependency: $dep"; done
docker info >/dev/null 2>&1 || die "Start Docker Desktop first."

WORKROOT="$(pwd)"
TMPDIR_LOCAL="$(mktemp -d "${TMPDIR:-/tmp}/voyager_build.XXXXXX")"
cleanup() { [[ $KEEP_TMP -eq 0 ]] && rm -rf "$TMPDIR_LOCAL" || echo "ℹ︎ Temp kept: $TMPDIR_LOCAL"; }
trap cleanup EXIT
mkdir -p "$OUT_DIR"

echo "▶ Fetching Oryx layout info for ${LAYOUT_ID} (${GEOMETRY}) ..."
GRAPHQL_PAYLOAD=$(
  cat <<'JSON'
{"query":"query getLayout($hashId: String!, $revisionId: String!, $geometry: String) {layout(hashId: $hashId, geometry: $geometry, revisionId: $revisionId) {  revision { hashId, qmkVersion, title }}}","variables":{"hashId":"__HASH__","geometry":"__GEOM__","revisionId":"latest"}}
JSON
)
GRAPHQL_PAYLOAD="${GRAPHQL_PAYLOAD/__HASH__/$LAYOUT_ID}"
GRAPHQL_PAYLOAD="${GRAPHQL_PAYLOAD/__GEOM__/$GEOMETRY}"

RESP=$(curl -sS --location --compressed 'https://oryx.zsa.io/graphql' \
  --header 'Content-Type: application/json' --data "$GRAPHQL_PAYLOAD") || die "Oryx GraphQL failed"

HASH_ID=$(echo "$RESP" | jq -r '.data.layout.revision.hashId // empty')
QMK_VERSION_RAW=$(echo "$RESP" | jq -r '.data.layout.revision.qmkVersion // empty')
CHANGE_DESC=$(echo "$RESP" | jq -r '.data.layout.revision.title // empty')
[[ -n "$HASH_ID" && -n "$QMK_VERSION_RAW" ]] || die "Bad Oryx response (check layout id/geometry)."

QMK_VERSION_MAJOR=$(printf "%.0f" "$QMK_VERSION_RAW" 2>/dev/null || true)
[[ "$QMK_VERSION_MAJOR" =~ ^[0-9]+$ ]] || die "Unexpected qmkVersion: $QMK_VERSION_RAW"
[[ -n "$CHANGE_DESC" && "$CHANGE_DESC" != "null" ]] || CHANGE_DESC="latest layout modification made with Oryx"

echo "  • Revision: $HASH_ID"
echo "  • QMK version: $QMK_VERSION_RAW (major $QMK_VERSION_MAJOR)"
echo "  • Title: $CHANGE_DESC"

echo "▶ Downloading & flattening Oryx source ..."
SRC_ZIP="$TMPDIR_LOCAL/source.zip"
curl -sSL --compressed "https://oryx.zsa.io/source/${HASH_ID}" -o "$SRC_ZIP" || die "Download source failed"
# IMPORTANT: -j to junk internal paths so files land directly under $TMPDIR_LOCAL/$LAYOUT_ID
unzip -oqj "$SRC_ZIP" "*_source/*" -d "$TMPDIR_LOCAL/$LAYOUT_ID"
rm -f "$SRC_ZIP"

# Prepare QMK
if [[ -z "$QMK_DIR" ]]; then
  QMK_DIR="$TMPDIR_LOCAL/qmk_firmware"
  echo "▶ Cloning zsa/qmk_firmware @ firmware${QMK_VERSION_MAJOR} ..."
  if ! git clone --depth 1 --branch "firmware${QMK_VERSION_MAJOR}" https://github.com/zsa/qmk_firmware.git "$QMK_DIR" 2>/dev/null; then
    git clone --depth 1 https://github.com/zsa/qmk_firmware.git "$QMK_DIR"
    git -C "$QMK_DIR" fetch origin "firmware${QMK_VERSION_MAJOR}" --depth 1
    git -C "$QMK_DIR" checkout -B "firmware${QMK_VERSION_MAJOR}" "FETCH_HEAD"
  fi
  git -C "$QMK_DIR" submodule update --init --recursive --depth=1
else
  echo "▶ Using existing QMK dir: $QMK_DIR"
  [[ -d "$QMK_DIR/.git" ]] || die "QMK_DIR is not a git repo: $QMK_DIR"
  git -C "$QMK_DIR" fetch origin "firmware${QMK_VERSION_MAJOR}" --depth 1
  git -C "$QMK_DIR" checkout -B "firmware${QMK_VERSION_MAJOR}" "FETCH_HEAD"
  git -C "$QMK_DIR" submodule update --init --recursive --depth=1
fi

if [[ "$QMK_VERSION_MAJOR" -ge 24 ]]; then
  KBD_DIR="$QMK_DIR/keyboards/zsa"
  MAKE_PREFIX="zsa/"
else
  KBD_DIR="$QMK_DIR/keyboards"
  MAKE_PREFIX=""
fi

echo "▶ Installing keymap into QMK ..."
KEYMAP_DST="$KBD_DIR/${GEOMETRY}/keymaps/${LAYOUT_ID}"
rm -rf "$KEYMAP_DST"
mkdir -p "$KEYMAP_DST"
# Copy CONTENTS (including dotfiles) directly into the keymap folder
cp -R "$TMPDIR_LOCAL/$LAYOUT_ID"/. "$KEYMAP_DST/"

# Sanity check (this is what QMK looks for)
[[ -f "$KEYMAP_DST/keymap.c" || -f "$KEYMAP_DST/keymap.json" ]] || die "Keymap missing keymap.c/json at $KEYMAP_DST"
[[ -f "$KEYMAP_DST/rules.mk" || -f "$KEYMAP_DST/config.h" ]] || true

echo "▶ Pulling Docker image: $DOCKER_IMAGE"
docker pull "$DOCKER_IMAGE" >/dev/null

HOST_CPUS=$(sysctl -n hw.ncpu 2>/dev/null || echo 2)
echo "▶ Verifying keymap path inside container:"
docker run --rm -v "$QMK_DIR:/src" "$DOCKER_IMAGE" /bin/sh -lc \
  'ls -la "/src/'"keyboards/${MAKE_PREFIX}../${GEOMETRY}/keymaps/${LAYOUT_ID}"'" 2>/dev/null || true'
echo "▶ Building: make ${MAKE_PREFIX}${GEOMETRY}:${LAYOUT_ID} (-j${HOST_CPUS})"
docker run --rm \
  -v "$QMK_DIR:/src" \
  "$DOCKER_IMAGE" /bin/sh -lc "make -C /src -j${HOST_CPUS} ${MAKE_PREFIX}${GEOMETRY}:${LAYOUT_ID}"

echo "▶ Locating artifact ..."
NORMALIZED_GEOM="${GEOMETRY//\//_}"
ARTIFACT=$(find "$QMK_DIR" -type f \( -name "*${NORMALIZED_GEOM}*.bin" -o -name "*${NORMALIZED_GEOM}*.hex" \) -print0 |
  xargs -0 ls -t 2>/dev/null | head -n1 || true)
if [[ -z "$ARTIFACT" ]]; then
  ARTIFACT=$(find "$QMK_DIR/.build" -type f \( -name "*.bin" -o -name "*.hex" \) -print0 |
    xargs -0 ls -t 2>/dev/null | head -n1 || true)
fi
[[ -n "$ARTIFACT" ]] || die "Build finished but no artifact found."

mkdir -p "$OUT_DIR"
OUT_PATH="$OUT_DIR/$(basename "$ARTIFACT")"
cp -f "$ARTIFACT" "$OUT_PATH"

echo "✅ Done!"
echo "• Output: $OUT_PATH"
echo "• Built from: layout=${LAYOUT_ID}, geometry=${GEOMETRY}, qmkVersion=${QMK_VERSION_RAW}, title='${CHANGE_DESC}'"
