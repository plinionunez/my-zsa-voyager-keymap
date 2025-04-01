#ifdef CHORDAL_HOLD
#define LAYOUT_LR(                                     \
    k00, k01, k02, k03, k04, k05,                      \
    k10, k11, k12, k13, k14, k15,                      \
    k20, k21, k22, k23, k24, k25,                      \
    k30, k31, k32, k33, k34, k35,                      \
                             k40, k41,                 \
                                                       \
                         k50, k51, k52, k53, k54, k55, \
                         k60, k61, k62, k63, k64, k65, \
                         k70, k71, k72, k73, k74, k75, \
                         k80, k81, k82, k83, k84, k85, \
                    k90, k91)                          \
    LAYOUT(k00, k01, k02, k03, k04, k05,   k50, k51, k52, k53, k54, k55, \
           k10, k11, k12, k13, k14, k15,   k60, k61, k62, k63, k64, k65, \
           k20, k21, k22, k23, k24, k25,   k70, k71, k72, k73, k74, k75, \
           k30, k31, k32, k33, k34, k35,   k80, k81, k82, k83, k84, k85, \
                               k40, k41,   k90, k91)
// Handedness for Chordal Hold.
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
  LAYOUT_LR(
  '*'    , '*'    , '*'    , '*'    , '*'    , '*'    ,
  '*'    , 'L'    , 'L'    , 'L'    , 'L'    , 'L'    ,
  '*'    , 'L'    , 'L'    , 'L'    , 'L'    , 'L'    ,
  '*'    , 'L'    , 'L'    , 'L'    , 'L'    , 'L'    ,
                                               'L'    , 'L'    ,

                    '*'    , '*'    , '*'    , '*'    , '*'    , '*'    ,
                    'R'    , 'R'    , 'R'    , 'R'    , 'R'    , '*'    ,
                    'R'    , 'R'    , 'R'    , 'R'    , 'R'    , '*'    ,
                    'R'    , 'R'    , 'R'    , 'R'    , 'R'    , '*'    ,
           'R'    , '*'
);
#endif  // CHORDAL_HOLD
//
// bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
//                       uint16_t other_keycode, keyrecord_t* other_record) {
//   // Exceptionally consider the following chords as holds, even though they
//   // are on the same hand in Dvorak.
//   switch (tap_hold_keycode) {
//     case MT(MOD_LGUI, KC_D):
//       if (other_keycode == KC_TAB) { return true; }
//       if (other_keycode == KC_Z) { return true; }
//       if (other_keycode == KC_R) { return true; }
//       if (other_keycode == KC_T) { return true; }
//       if (other_keycode == KC_W) { return true; }
//       break;
//     case MT(MOD_RSFT, KC_J):
//       if (other_keycode == MT(MOD_RCTL, KC_SCLN)) { return true; }
//       break;
//   }
// 
//   // Also allow same-hand holds when the other key is in the rows below the
//   // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
//   // if (tap_hold_record->event.key.row % (MATRIX_ROWS / 2) >= 5) { return true; }
// 
//   // Otherwise defer to the opposite hands rule.
//   return get_chordal_hold_default(tap_hold_record, other_record);
// }

/*
#include "features/achordion.h"

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand in Dvorak.
  switch (tap_hold_keycode) {
    case MT(MOD_LGUI, KC_D):
      if (other_keycode == KC_TAB) { return true; }
      if (other_keycode == KC_Z) { return true; }
      if (other_keycode == KC_R) { return true; }
      if (other_keycode == KC_T) { return true; }
      if (other_keycode == KC_W) { return true; }
      break;
    case MT(MOD_RSFT, KC_J):
      if (other_keycode == MT(MOD_RCTL, KC_SCLN)) { return true; }
      break;
  }

  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  // if (tap_hold_record->event.key.row % (MATRIX_ROWS / 2) >= 5) { return true; }

  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case MT(MOD_LGUI, KC_GRAVE):
    case KC_RIGHT_SHIFT:
    case MT(MOD_LCTL, KC_ESCAPE):

    case LT(1,KC_BSPC):
    case LT(1,KC_SPACE):
    case LT(2,KC_BSPC):

    case MO(1):
    case MO(2):
    case MO(3):

      return 0;
  }

  return 700;  // Otherwise use a timeout of 700 ms.
}

bool achordion_eager_mod(uint8_t mod) {
  return true;  // Eagerly apply all mods.
}

uint16_t achordion_streak_chord_timeout(
    uint16_t tap_hold_keycode, uint16_t next_keycode) {
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 0;  // Disable streak detection on layer-tap keys.
  }

  // Otherwise, tap_hold_keycode is a mod-tap key.
  uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & MOD_LSFT) != 0) {
    return 50;  // A shorter streak timeout for Shift mod-tap keys.
  } else {
    return 100;  // A longer timeout otherwise.
  }
}
*/
