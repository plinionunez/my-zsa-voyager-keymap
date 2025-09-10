#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  MAC_MISSION_CONTROL,
  MAC_SPOTLIGHT,
  MAC_SIRI,
};



#define DUAL_FUNC_0 LT(9, KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    MT(MOD_LSFT, KC_ESCAPE),KC_W,           KC_F,           KC_MINUS,       KC_PLUS,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LBRC,        KC_RBRC,        KC_U,           KC_Y,           DUAL_FUNC_0,    
    KC_Q,           MT(MOD_LCTL, KC_R),MT(MOD_LALT, KC_S),KC_P,           KC_G,           KC_TAB,                                         KC_BSLS,        KC_J,           KC_L,           MT(MOD_RALT, KC_E),MT(MOD_RCTL, KC_I),KC_SCLN,        
    KC_A,           KC_X,           KC_C,           MT(MOD_LGUI, KC_T),KC_D,           LSFT(KC_TAB),                                   KC_SLASH,       KC_H,           MT(MOD_RGUI, KC_N),KC_COMMA,       KC_DOT,         KC_O,           
    MT(MOD_LSFT, KC_Z),KC_MS_BTN1,     KC_MS_BTN2,     KC_V,           KC_B,           LT(2, KC_BSPC),                                 KC_DELETE,      KC_K,           KC_M,           KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_RSFT, KC_QUOTE),
                                                    LT(4, KC_MINUS),MT(MOD_LGUI, KC_TAB),                                LT(1, KC_ENTER),LT(3, KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    TO(0),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          ST_MACRO_0,     ST_MACRO_1,     TO(3),          
    KC_NO,          KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_NO,          KC_NO,          LGUI(KC_UP),                                    KC_NO,          KC_NO,          ST_MACRO_2,     KC_UP,          LALT(KC_RIGHT), KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_LEFT_GUI,    KC_PAGE_UP,     LGUI(KC_DOWN),                                  KC_NO,          LGUI(KC_LEFT),  LALT(KC_LEFT),  KC_DOWN,        KC_RIGHT,       LGUI(KC_RIGHT), 
    KC_LEFT_SHIFT,  KC_NO,          KC_NO,          KC_NO,          KC_PGDN,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_LEFT,        KC_NO,          KC_NO,          KC_NO,          
                                                    KC_NO,          KC_LEFT_GUI,                                    KC_TRANSPARENT, KC_NO
  ),
  [2] = LAYOUT_voyager(
    TO(0),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          ST_MACRO_3,     KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          ST_MACRO_4,     KC_NO,          LALT(KC_DELETE),KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          LGUI(KC_BSPC),  LALT(KC_BSPC),  KC_NO,          KC_DELETE,      LGUI(KC_DELETE),
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_BSPC,        KC_NO,          KC_NO,          KC_NO,          
                                                    KC_NO,          KC_NO,                                          KC_NO,          KC_NO
  ),
  [3] = LAYOUT_voyager(
    TO(0),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TO(4),          
    KC_NO,          KC_2,           KC_3,           KC_MINUS,       KC_PLUS,        KC_NO,                                          KC_NO,          KC_SLASH,       KC_ASTR,        KC_8,           KC_9,           KC_NO,          
    KC_1,           KC_NO,          KC_EQUAL,       KC_4,           KC_5,           KC_NO,                                          KC_TRANSPARENT, KC_6,           KC_7,           KC_TRANSPARENT, KC_TRANSPARENT, KC_0,           
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    LT(5, KC_MINUS),KC_NO,                                          KC_ENTER,       KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    TO(0),          KC_NO,          KC_NO,          LCTL(KC_MINUS), LCTL(KC_EQUAL), LGUI(KC_GRAVE),                                 KC_NO,          KC_NO,          KC_NO,          KC_RCBR,        KC_RBRC,        TO(5),          
    KC_NO,          KC_EXLM,        KC_HASH,        KC_CIRC,        KC_GRAVE,       LCTL(KC_TAB),                                   KC_PIPE,        KC_PIPE,        KC_RPRN,        KC_LCBR,        KC_LBRC,        KC_COLN,        
    KC_AT,          KC_TILD,        KC_EQUAL,       KC_DLR,         KC_PERC,        LCTL(LSFT(KC_TAB)),                                KC_QUES,        KC_QUES,        KC_LPRN,        KC_LABK,        KC_RABK,        KC_ASTR,        
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_AMPR,        KC_NO,          KC_NO,          KC_DQUO,        
                                                    KC_TRANSPARENT, KC_NO,                                          KC_ENTER,       LT(5, KC_SPACE)
  ),
  [5] = LAYOUT_voyager(
    TO(0),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TO(6),          
    KC_NO,          MAC_SPOTLIGHT,  MAC_SIRI,       KC_BRIGHTNESS_UP,LGUI(LSFT(KC_5)),KC_NO,                                          KC_NO,          KC_NO,          KC_AUDIO_VOL_UP,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_NO,          
    MAC_MISSION_CONTROL,KC_NO,          KC_NO,          KC_BRIGHTNESS_DOWN,LGUI(LSFT(KC_4)),KC_NO,                                          KC_NO,          KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_NO,          KC_NO,          KC_MEDIA_NEXT_TRACK,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_NO,                                          KC_NO,          KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    TO(0),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TO(0),          
    KC_NO,          RGB_VAD,        RGB_VAI,        KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,QK_DYNAMIC_TAPPING_TERM_PRINT,KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_NO,          KC_NO,                                          KC_NO,          KC_NO
  ),
};



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LCTL, KC_R):
            return g_tapping_term + 50;
        case MT(MOD_LALT, KC_S):
            return g_tapping_term + 50;
        case LT(4, KC_MINUS):
            return g_tapping_term -75;
        case MT(MOD_RALT, KC_E):
            return g_tapping_term + 50;
        case MT(MOD_RCTL, KC_I):
            return g_tapping_term + 50;
        default:
            return g_tapping_term;
    }
}


extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,255,255}, {7,255,255}, {7,255,255}, {253,239,176}, {148,255,187}, {0,0,0}, {7,255,255}, {253,239,176}, {253,239,176}, {7,255,255}, {7,255,255}, {7,255,255}, {7,255,255}, {7,255,255}, {7,255,255}, {253,239,176}, {7,255,255}, {7,255,255}, {253,239,176}, {86,255,138}, {86,255,138}, {7,255,255}, {7,255,255}, {0,255,255}, {194,255,255}, {253,239,176}, {0,0,0}, {194,255,255}, {194,255,255}, {7,255,255}, {7,255,255}, {7,255,255}, {7,255,255}, {7,255,255}, {7,255,255}, {253,239,176}, {253,239,176}, {7,255,255}, {7,255,255}, {7,255,255}, {253,239,176}, {7,255,255}, {7,255,255}, {7,255,255}, {0,255,255}, {7,255,255}, {7,255,255}, {0,0,0}, {0,0,0}, {253,239,176}, {114,255,255}, {86,255,138} },

    [1] = { {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {7,255,255}, {7,255,255}, {0,0,0}, {0,0,0}, {114,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {7,255,255}, {148,255,187}, {114,255,178}, {7,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {148,255,187}, {0,255,255}, {0,0,0}, {7,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,138}, {86,255,138}, {114,255,255}, {0,0,0}, {0,0,0}, {86,255,138}, {114,255,255}, {148,255,187}, {0,0,0}, {0,0,0}, {148,255,187}, {148,255,187}, {114,255,255}, {114,255,255}, {148,255,187}, {0,255,255}, {0,0,0}, {114,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {114,255,255}, {0,0,0} },

    [2] = { {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {253,239,176}, {0,255,255}, {0,0,0}, {0,255,255}, {253,239,176}, {0,255,255}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,138}, {86,255,138}, {253,239,176}, {148,255,187}, {0,0,0}, {86,255,138}, {0,0,0}, {194,255,255}, {86,255,138}, {86,255,138}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {45,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,138}, {0,0,0}, {22,255,255}, {194,255,255}, {86,255,138}, {86,255,138}, {0,0,0}, {0,0,0}, {86,255,138}, {86,255,138}, {0,0,0}, {0,0,0}, {86,255,138}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,138} },

    [4] = { {0,255,255}, {0,0,0}, {0,0,0}, {148,255,187}, {148,255,187}, {148,255,187}, {0,0,0}, {194,255,255}, {194,255,255}, {194,255,255}, {194,255,255}, {148,255,187}, {194,255,255}, {194,255,255}, {194,255,255}, {194,255,255}, {194,255,255}, {148,255,187}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {194,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {148,255,187}, {253,239,176}, {194,255,255}, {0,0,0}, {194,255,255}, {86,255,138}, {148,255,187}, {253,239,176}, {194,255,255}, {0,0,0}, {194,255,255}, {86,255,138}, {194,255,255}, {194,255,255}, {194,255,255}, {0,0,0}, {0,0,0}, {194,255,255}, {0,0,0}, {0,0,0}, {194,255,255}, {0,0,0}, {45,255,255} },

    [5] = { {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {45,255,255}, {253,239,176}, {148,255,187}, {221,255,255}, {0,0,0}, {45,255,255}, {0,0,0}, {0,0,0}, {148,255,187}, {221,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {45,255,255}, {0,0,0}, {0,0,0}, {86,255,255}, {45,255,255}, {148,255,187}, {0,0,0}, {0,0,0}, {253,239,176}, {86,255,255}, {0,0,0}, {0,0,0}, {45,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {166,255,255}, {148,255,187}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {22,255,255}, {22,255,255}, {22,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 0:
        set_layer_color(0);
        break;
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
      case 3:
        set_layer_color(3);
        break;
      case 4:
        set_layer_color(4);
        break;
      case 5:
        set_layer_color(5);
        break;
      case 6:
        set_layer_color(6);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX: 
    // Mouse keys with modifiers work inconsistently across operating systems, this makes sure that modifiers are always
    // applied to the mouse key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
    if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(1);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_LEFT))SS_DELAY(100)  SS_LGUI(SS_LSFT(SS_TAP(X_RIGHT)))SS_DELAY(100)  SS_LGUI(SS_TAP(X_C)));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_A))SS_DELAY(100)  SS_LGUI(SS_TAP(X_C)));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_LEFT))SS_DELAY(20)  SS_LALT(SS_TAP(X_RIGHT))SS_DELAY(20)  SS_LALT(SS_LSFT(SS_TAP(X_LEFT)))SS_DELAY(20)  SS_LGUI(SS_TAP(X_C)));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_RIGHT))SS_DELAY(20)  SS_LGUI(SS_TAP(X_BSPC)));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_LEFT))SS_DELAY(20)  SS_LALT(SS_TAP(X_DELETE)));
    }
    break;
    case MAC_MISSION_CONTROL:
      HCS(0x29F);
    case MAC_SPOTLIGHT:
      HCS(0x221);
    case MAC_SIRI:
      HCS(0xCF);

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          layer_move(1);
        } else {
          layer_move(1);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_SHIFT);
        } else {
          unregister_code16(KC_RIGHT_SHIFT);
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
