
/*

   Left-handed (i.e. right side) controller for Railworks (Train Simulator 20xx)

   Main persistent layer is for driving trains
   Another persistent layer is included for using the Route/Scenario Editors

*/
#include QMK_KEYBOARD_H
#include "msv.h"
#include "msv_td_actions.h"

#define _DRIVE 0 // Railworks - Drive Trains
#define _RTED  1   // Railworks - Route Editor
#define _RAISE 2

enum custom_keycodes {
  DRIVE = SAFE_RANGE,
  RTED,
  RAISE,
};

/*
#define AUDIO_CLICKY
#define AUDIO_CLICKY_ENABLE
#define AUDIO_CLICKY_FREQ_DEFAULT 1200.0f
#define AUDIO_CLICKY_FREQ_MIN 1100.0f
#define AUDIO_CLICKY_FREQ_MAX 1300.0f
#define AUDIO_CLICKY_FREQ_FACTOR 1.18921f
#define AUDIO_CLICKY_FREQ_RANDOMNESS 0.05f
*/

#define KSCTL LCTL(KC_LSFT)
#define CTLC  LCTL(KC_C)
#define CTLV  LCTL(KC_V)
#define CTLX  LCTL(KC_X)
#define CTLZ  LCTL(KC_Z)
#define CTLS  LCTL(KC_S)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DRIVE] = KEYMAP(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            KC_F1,   KC_1,    KC_2,    KC_3,  LSFT(KC_2), KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_TAB,  KC_SCLN, KC_W,    KC_QUOT, KC_SPC, KC_ESC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_F2,   KC_D,    KC_S,    KC_A,    KC_B,    KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          KC_T,    KC_Y,    KC_F,    KC_H,    KC_I,    KC_V,    KC_F12,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                    RAISE,   KC_Q,    KC_E
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  
  [_RTED] = KEYMAP(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_DEL,  KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_ESC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_F2,   KC_LEFT, KC_DOWN, KC_RGHT,  KC_NO,  KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   RAISE,   KC_LCTL, KC_LSFT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

  [_RAISE] = KEYMAP(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                             KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_F3,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   LCTL(KC_MINS),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_F4,   KC_LEFT, KC_DOWN, KC_RGHT,LSFT(KC_V),LCTL(KC_PLUS),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,            RTED,   KC_F,    KC_X,  LSFT(KC_H),_______,_______,  RESET,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, DRIVE,   KC_PENT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DRIVE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DRIVE);
      }
      return false;
      break;
      
    case RTED:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_RTED);
      }
      return false;
      break;
            
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    }
  
  #ifdef MSV_ONLY
    return msv_only_process(keycode,record);
  #endif

  return true;
}

