// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"
#include <process_unicode_common.h>

extern keymap_config_t keymap_config;
void register_hex32(uint32_t hex);
uint32_t characterArray[] = { 0x1D43,0x1D47,0x1D9C,0x1D48,0x1D49,0x1DA0,0x1D4D,0x02B0,0x1DA6,0x02B2,0x1D4F,0x02E1,0x1D50,0x207f,0x1D52,0x1D56,0x1D60,0x02B3,0x02E2,0x1D57,0x1D58,0x1D5B,0x02B7,0x02E3,0x02B8,0x1DBB };
uint16_t repeat_mode;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FN,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV,
  KC_NOMODE,
  KC_WIDE,
  KC_SCRIPT,
  KC_BLOCKS,
  KC_REACT,
  KC_SMOL
};


// Readability shortcuts
#define FN_ESC MT(MOD_LCTL, KC_ESC)
#define FN_ENT SFT_T(KC_ENT) 
#define FN_LEFT GUI_T(KC_LEFT)
#define FN_DRP LGUI(LSFT(KC_5))
#define FN_WA LGUI(LCTL(LSFT(KC_4)))
#define SLEEP LCTL(LSFT(KC_PWR))
#define FN MO(_FN)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *    ----------------
 *   == Special Keys ==
 *    ----------------
 *  -  FN_ESC  - Escape when tapped, Control when held
 *  -  FN_ENT  - Enter when tapped, Right Shift when held
 *  -  FN_LEFT - Left arrow when tapped, Command when held
 *    
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  FN  | Ctrl | Alt  | GUI  |Lower |Shift |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {FN_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, FN_ENT },
  {FN,      KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_LSFT, KC_SPC,  RAISE,   FN_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   =  |   {  |   }  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Play | Prev | Next | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_EQL,     KC_LCBR, KC_RCBR, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    KC_MPLY,    KC_MPRV, KC_MNXT, KC_MUTE}
},

/* Raise
 *    ----------------
 *   == Special Keys ==
 *    ----------------
 *  -  FN_DRP  - Screenshot with DropShare: Command + Shift + 5
 *
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   +  |   [  |   ]  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |DrpShr| Vol- | Vol+ | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, FN_DRP,  KC_VOLD, KC_VOLU, KC_MUTE}
},


/* Fn
 *  Hyper keys used for dropshare
 *  R - start screen recording
 *  S - screenshot and open in Skitch
 *  V - upload clipboard content
 *  W - screenshot to clipboard
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |      |CCS+W |      |Hypr R|      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Hypr S|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | LED  |      |      |Hypr V|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = { 
  {_______, _______, FN_WA,      _______, HYPR(KC_R), _______, _______, _______, _______, _______, _______, KC_DELT},
  {_______, _______, HYPR(KC_S), _______, _______,    _______, _______, _______, _______, _______, _______, _______},
  {_______, BACKLIT, _______,    _______, HYPR(KC_V), _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______,    _______, _______,    _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END }
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |Sleep |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      | wide |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, KC_REACT, KC_SMOL,   _______, SLEEP  },
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  KC_BLOCKS, KC_SCRIPT,   KC_WIDE, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, KC_NOMODE, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______}
}


};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void keyboard_post_init_user(void) {
    set_unicode_input_mode(UC_MAC);
}

void matrix_init_user(void) {
    repeat_mode = KC_NOMODE;
};

bool process_record_glyph_replacement(uint16_t keycode, keyrecord_t *record, uint32_t baseAlphaLower, uint32_t baseAlphaUpper, uint32_t zeroGlyph, uint32_t baseNumberOne, uint32_t spaceGlyph) {
    uint8_t temp_mod = get_mods();
    uint8_t temp_osm = get_oneshot_mods();
    if ((((temp_mod | temp_osm) & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI))) == 0) {
        if (KC_A <= keycode && keycode <= KC_Z) {
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();

                unicode_input_start();
                uint32_t base = ((temp_mod | temp_osm) & MOD_MASK_SHIFT) ? baseAlphaUpper : baseAlphaLower;
                register_hex32(base + (keycode - KC_A));
                unicode_input_finish();

                set_mods(temp_mod);
            }
            return false;
        } else if (keycode == KC_0) {
            if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {  // skip shifted numbers, so that we can still use symbols etc.
                return process_record_kb(keycode, record);
            }
            if (record->event.pressed) {
                unicode_input_start();
                register_hex32(zeroGlyph);
                unicode_input_finish();
            }
            return false;
        } else if (KC_1 <= keycode && keycode <= KC_9) {
            if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {  // skip shifted numbers, so that we can still use symbols etc.
                return process_record_kb(keycode, record);
            }
            if (record->event.pressed) {
                unicode_input_start();
                register_hex32(baseNumberOne + (keycode - KC_1));
                unicode_input_finish();
            }
            return false;
        } else if (keycode == KC_SPACE) {
            if (record->event.pressed) {
                unicode_input_start();
                register_hex32(spaceGlyph);  // em space
                unicode_input_finish();
            }
            return false;
        }
    }
    return process_record_kb(keycode, record);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            persistant_default_layer_set(1UL<<_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
          return false;
          break;
        case KC_NOMODE:
            if (record->event.pressed) {
                if (repeat_mode != KC_NOMODE) {
                    dprint("Disabling repeat mode\n");
                }
                repeat_mode = keycode;
            }
            return false;
        case KC_WIDE:
            if (record->event.pressed) {
                if (repeat_mode != KC_WIDE) {
                    dprint("Enabling wide mode\n");
                }
                repeat_mode = keycode;
            }
            return false;
        case KC_SCRIPT:
            if (record->event.pressed) {
                if (repeat_mode != KC_SCRIPT) {
                    dprint("Enabling calligraphy mode\n");
                }
                repeat_mode = keycode;
            }
            return false;
        case KC_BLOCKS:
            if (record->event.pressed) {
                if (repeat_mode != KC_BLOCKS) {
                    dprint("Enabling blocks mode\n");
                }
                repeat_mode = keycode;
            }
            return false;
        case KC_REACT:
            if (record->event.pressed) {
                if (repeat_mode != KC_REACT) {
                    dprint("Enabling reactji mode\n");
                }
                repeat_mode = keycode;
            }
            return false;
        case KC_SMOL:
            if (record->event.pressed) {
                if (repeat_mode != KC_SMOL) {
                    dprint("Enabling smalltext mode\n");
                }
                repeat_mode = keycode;
            }
            return false;
    }
    if (repeat_mode == KC_WIDE) {
        if (((KC_A <= keycode) && (keycode <= KC_0)) || keycode == KC_SPACE) {
            return process_record_glyph_replacement(keycode, record, 0xFF41, 0xFF21, 0xFF10, 0xFF11, 0x2003);
        }
    } else if (repeat_mode == KC_SCRIPT) {
        if (((KC_A <= keycode) && (keycode <= KC_0)) || keycode == KC_SPACE) {
            return process_record_glyph_replacement(keycode, record, 0x1D4EA, 0x1D4D0, 0x1D7CE, 0x1D7C1, 0x2002);
        }
    } else if (repeat_mode == KC_BLOCKS) {
        if (((KC_A <= keycode) && (keycode <= KC_0))) {
            if (record->event.pressed) {
                SEND_STRING(":-");
                tap_code(keycode);
                SEND_STRING(":");
            }
            return false;
        }
        if (keycode == KC_SPACE) {
            if (record->event.pressed) {
                unicode_input_start();
                register_hex32(0x2003);
                unicode_input_finish();
            }
            return false;
        }
    } else if (repeat_mode == KC_REACT) {
        if (((KC_A <= keycode) && (keycode <= KC_0))) {
            if (record->event.pressed) {
                SEND_STRING("+:-");
                tap_code(keycode);
                SEND_STRING(":");
                tap_code(KC_ENT);
            }
            return false;
        }
    } else if (repeat_mode == KC_SMOL) {
        if ((KC_A <= keycode) && (keycode <= KC_Z)) {
            uint32_t glyph = characterArray[keycode - KC_A];
            if (record->event.pressed) {
                unicode_input_start();
                register_hex32(glyph);
                unicode_input_finish();
            }
            return false;
        }
        if (keycode == KC_EXLM) {
            if (record->event.pressed) {
                unicode_input_start();
                register_hex32(0x1D4E);
                unicode_input_finish();
            }
            return false;
        }
        if (keycode == KC_SLSH) {
            if (record->event.pressed) {
                unicode_input_start();
                register_hex32(0x2C0);
                unicode_input_finish();
            }
            return false;
        }
    }
    return true;
}

