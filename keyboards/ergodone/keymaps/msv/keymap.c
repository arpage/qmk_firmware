#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE      0 // default layer
#define FL1       1 // symbols
#define FL2       2 // media keys
#define RAILWORKS 3 // Railworks/TS2018 keys
#define RWBUILD   4 // TS Route editor

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  6   |           |   7  |   8  |   9  |   0  |   -  |   =  | Del    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  | Bsp    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Fn1    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------|  \   |           |  /   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  Up  |   '    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Home | LGui | End  | LAlt |                                       | RAlt | Fn2  |  Le  |  Do  |  Ri  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Ins  | PtSc |       | L2   | Esc    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Del  |       | PgUp |        |      |
 *                                 | Space| Bsp  |------|       |------| Enter  |Space |
 *                                 |      |      | Tab  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,
        KC_TAB ,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC,
        MO(FL1),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_BSLS,
        KC_LCTL,KC_LGUI,KC_HOME,KC_END,KC_LALT,
                                        KC_INS, KC_PSCR,
                                                        KC_DEL,
                                        KC_SPC, KC_BSPC,KC_TAB,
                                        
        // right hand
        KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,
        KC_RBRC,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_ESC,
        KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,        KC_ENTER,
        KC_SLSH,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_UP,  KC_QUOT,
        KC_RALT,MO(FL2),KC_LEFT,KC_DOWN,KC_RIGHT,
        KC_CALC,        KC_ESC,
        KC_PGUP,
        KC_PGDN,KC_ENT, KC_SPC
    ),

/* Keymap 1: Symbol Layer
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | Esc     |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | Version |      |      |      |      |      |      |           |      |      |      |      |      |      | RW     |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |      |      | RWB    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      | PgUp |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      | Home | PgDn | End  |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[FL1] = LAYOUT_ergodox(
       // left hand
       KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______, _______,_______,_______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  TO(BASE),
       _______, _______, _______,_______, _______, _______, TO(RAILWORKS),
                _______, _______,_______, _______, _______, TO(RWBUILD),
       _______, _______, _______,_______, _______, KC_PGUP, _______,
                         _______,_______, KC_HOME, KC_PGDN, KC_END,
       _______,   _______,
       _______,
       _______, _______, _______
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      | Prev | Play | Next |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CapsLk |      |MsLeft|MsDown|MsRght|      |------|           |------|      | VolD | Mute | VolU |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Stop |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |EEPROM| Menu |      | Lclk | Rclk |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | Reset|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[FL2] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_MS_U, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, KC_APP,  _______, KC_BTN1, KC_BTN2,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
       // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
                 _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,
       _______,  _______, _______, KC_MSTP, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______,  _______,
       _______,
       _______, _______, _______
),

[RAILWORKS] = LAYOUT_ergodox(
        // left hand
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,
        KC_TAB ,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC,
        MO(FL1),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_BSLS,
        KC_LCTL,KC_LGUI,KC_HOME,KC_END,KC_LALT,
                                        KC_INS, KC_PSCR,
                                                        KC_DEL,
                                        KC_SPC, KC_BSPC,KC_TAB,
        // right hand
        KC_F1,      KC_1,       KC_2,       KC_3,       LSFT(KC_2), _______,    _______,
        KC_TAB,     KC_SPC,     KC_SCLN,    KC_W,       KC_QUOT,    _______,    _______, 
                    KC_B,       KC_D,       KC_S,       KC_A,       _______,    _______,  
        KC_F2,      KC_L,       KC_I,       KC_UP,      KC_V,       LSFT(KC_V), _______,
                    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    LSFT(KC_W),
        KC_T,       KC_PENT,
        KC_F,
        KC_Y,       KC_E,       KC_Q
    ),  

[RWBUILD] = LAYOUT_ergodox(
        // left hand
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,
        KC_TAB ,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC,
        MO(FL1),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_BSLS,
        KC_LCTL,KC_LGUI,KC_HOME,KC_END,KC_LALT,
                                        KC_INS, KC_PSCR,
                                                        KC_DEL,
                                        KC_SPC, KC_BSPC,KC_TAB,
        // right hand
        KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,    _______,    _______,
        KC_TAB,     _______,    _______,    _______,    _______,   _______,    _______,
                    KC_BTN1,    KC_BTN2,    _______,    _______,   _______,    _______,
        KC_F2,      KC_C,       KC_V,       KC_UP,      _______,   _______,    _______,
                                KC_LEFT,    KC_DOWN,    KC_RGHT,   _______,    KC_DEL,
        _______,    _______,
        _______,
        LCTL(KC_LSFT), KC_LCTL, KC_LSFT
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(FL1)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

/*
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};
*/

void led_set_user(uint8_t usb_led) {
    
    uint8_t layer = biton32(layer_state);
    
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case BASE:
             ergodox_right_led_1_on();
             break;
        case FL1:
             //ergodox_right_led_2_on();
             break;                
        case RAILWORKS:
            //ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            //ergodox_right_led_3_on();
            break;
        case RWBUILD:
            ergodox_right_led_3_on();
            break;
        default:
           /*if (usb_led & (1<<USB_LED_NUM_LOCK)) {
               ergodox_right_led_1_on();
           } else {
               ergodox_right_led_1_off();
           }
           if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
               ergodox_right_led_2_on();
           } else {
               ergodox_right_led_2_off();
           }
           if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
               ergodox_right_led_3_on();
           } else {
               ergodox_right_led_3_off();
           }*/
           break;
    }

}
