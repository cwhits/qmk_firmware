// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#include "timer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FN 3
#define _TENKEY 4
//  #define _MUSIC 5
#define _PLOVER 6
#define _ADJUST 16

// Readability shortcuts
#define ESC_CTL MT(MOD_LCTL, KC_ESC)
#define SFT_CAP SFT_T(KC_CAPS) 
#define CAI LALT(LCTL(KC_INS))
#define FN_LEFT GUI_T(KC_LEFT)
#define DRPSHR LGUI(LSFT(KC_5))
#define FN MO(_FN)
#define FN_ENT SFT_T(KC_ENT) 

// Macro name shortcuts
#define QWERTY M(_QWERTY)
#define LOWER M(_LOWER)
#define RAISE M(_RAISE)
#define LED M(4)
//#define AUD_OFF M(5)
//#define AUD_ON M(6)
//#define MUS_OFF M(7)
//#define MUS_ON M(8)
//#define VC_IN M(9)
//#define VC_DE M(10)
#define PLOVER M(11)
#define EXT_PLV M(12)
#define SLEEP M(13)
#define EXT_TK M(14)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *    ----------------
 *   == Special Keys ==
 *    ----------------
 *  -  Left Shift when held, Caps Lock when tapped
 *  -  Enter when tapped, Right Shift when held
 *  -  Escape when tapped, Control when held
 *  -  Left arrow when tapped, Command when held
 *    
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  fn  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {ESC_CTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, FN_ENT },
  {FN,      KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   FN_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   =  |   {  |   }  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |C/A/I |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_EQL,  KC_LCBR, KC_RCBR, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______},
  {CAI,     _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   +  |   [  |   ]  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |DrpShr| Vol- | Vol+ | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, DRPSHR,  KC_VOLD, KC_VOLU, KC_MUTE}
},

/* Fn
 *  Hyper keys used for dropshare
 *  R - start screen recording
 *  S - screenshot and open in Skitch
 *  V - upload clipboard contente
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |Hypr R|      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Hypr S|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | LED  |      |      |Hypr V|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = { 
  {_______, _______, _______,    _______, HYPR(KC_R), _______, _______, _______, _______, _______, _______, KC_DELT},
  {_______, _______, HYPR(KC_S), _______, _______,    _______, _______, _______, _______, _______, _______, _______},
  {_______, LED,     _______,    _______, HYPR(KC_V), _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______,    _______, _______,    _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END }
},

/* Tenkey
 *
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      |      |      |      |      |      |   7  |   8  |   9  |   /  |      |
 * |-----------------------------------------------------------------------------------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   *  |      | 
 * |-----------------------------------------------------------------------------------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   +  |      | 
 * |-----------------------------------------------------------------------------------|
 * |      |      |      |      | Exit |             |   0  |      |   .  |   -  |      | 
 * `----------------------------------------------------------------------------------'
 */
[_TENKEY] = { /* Ten-key layer */
  {KC_TAB,  _______, _______, _______, _______, _______, _______, KC_7, KC_8,    KC_9,   KC_SLSH, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_4, KC_5,    KC_6,   KC_ASTR, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_1, KC_2,    KC_3,   KC_PLUS, _______},
  {_______, _______, _______, _______, EXT_TK,  _______, _______, KC_0, _______, KC_DOT, KC_MINS, _______}
},

/* Music (reserved for process_action_user)
 *
 */
/*[_MUSIC] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOWER,   XXXXXXX, XXXXXXX, RAISE,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},
*/
/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |Sleep |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/*
  [_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, SLEEP},
  {_______, _______, _______, AUD_ON,  AUD_OFF, AG_NORM, AG_SWAP, QWERTY,  _______, _______,  PLOVER, _______},
  {_______, VC_DE,   VC_IN,   MUS_ON,  MUS_OFF, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}
*/
[_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, SLEEP},
  {_______, _______, _______, _______, _______, _______, _______, QWERTY,  _______, _______, PLOVER,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};

const uint16_t PROGMEM fn_actions[] = {

};

#ifdef AUDIO_ENABLE
float tone_startup[][2] = {
  {440.0*pow(2.0,(31)/12.0), 12},
  {440.0*pow(2.0,(28)/12.0), 8},
  {440.0*pow(2.0,(19)/12.0), 8},
  {440.0*pow(2.0,(24)/12.0), 8},
  {440.0*pow(2.0,(28)/12.0), 20}
};

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);

float music_scale[][2] = SONG(MUSIC_SCALE_SOUND);
float goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _QWERTY:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
            #endif
            persistant_default_layer_set(1UL<<_QWERTY);
          }
          break;
        case _LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          break;
        case _RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          break;
        case 4:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
        case 5:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              audio_off();
            #endif
          }
        break;
        case 6:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              audio_on();
              PLAY_NOTE_ARRAY(tone_startup, false, 0);
            #endif
          }
        break;
        case 7:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              layer_off(_MUSIC);
              stop_all_notes();
            #endif
          }
        break;
        case 8:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(music_scale, false, 0);
              layer_on(_MUSIC);
            #endif
          }
        break;
        case 9:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              voice_iterate();
              PLAY_NOTE_ARRAY(music_scale, false, 0);
            #endif
          }
        break;
        case 10:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              voice_deiterate();
              PLAY_NOTE_ARRAY(music_scale, false, 0);
            #endif
          }
        break;
        case 11:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              stop_all_notes();
              PLAY_NOTE_ARRAY(tone_plover, false, 0);
              layer_off(_MUSIC);
            #endif
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_ADJUST);
            layer_on(_PLOVER);
            return MACRO( D(E), D(R), D(F), D(V), D(O), D(L), U(E), U(R), U(F), U(V), U(O), U(L), END );
            if (!eeconfig_is_enabled()) {
                eeconfig_init();
            }
            keymap_config.raw = eeconfig_read_keymap();
            keymap_config.nkro = 1;
            eeconfig_update_keymap(keymap_config.raw);
          }
        break;
        case 12:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
            #endif
            layer_off(_PLOVER);
            return MACRO( D(E), D(R), D(F), D(V), D(O), D(L), U(E), U(R), U(F), U(V), U(O), U(L), END );
          }
        break;

        // Lock screen on OSX
        // For some reason, this has to be a macro, otherwise the keydown and keyup
        // sequence is sometimes off and doesn't work
        // Tried ACTION_MODS_KEY(MOD_LCTL | MOD_LSFT, KC_EJCT) // LCTL(LSFT(KC_EJCT))
        // and it was inconsistent
        case 13:
          if (record->event.pressed) {
            return MACRO(
              D(LSFT),
              D(LCTL),
              T(POWER),
              U(LCTL),
              U(LSFT),
            END);
          }
        break;
        case 14:
          if (record->event.pressed) {
            layer_off(_TENKEY);
          }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
  #ifdef AUDIO_ENABLE
    _delay_ms(20); // stops the tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
  #endif
}

#ifdef AUDIO_ENABLE
void play_goodbye_tone()
{
  PLAY_NOTE_ARRAY(goodbye, false, 0);
  _delay_ms(150);
}

uint8_t starting_note = 0x0C;
int offset = 0;

void process_action_user(keyrecord_t *record) {

  if (IS_LAYER_ON(_MUSIC)) {
    if (record->event.pressed) {
        play_note(((double)220.0)*pow(2.0, -4.0)*pow(2.0,(starting_note + SCALE[record->event.key.col + offset])/12.0+(MATRIX_ROWS - record->event.key.row)), 0xF);
    } else {
        stop_note(((double)220.0)*pow(2.0, -4.0)*pow(2.0,(starting_note + SCALE[record->event.key.col + offset])/12.0+(MATRIX_ROWS - record->event.key.row)));
    }
  }

}
#endif
