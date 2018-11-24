#include QMK_KEYBOARD_H

#include "msv.h"
#include "action.h"
#include "quantum.h"
#include "process_keycode/process_tap_dance.h"

//Tap dance enums
enum {
  RS_CTL = 0,
  K5_CTL,
  KC_CTL,
  KV_CTL,
  KZ_CTL,
  KX_CTL,
  KA_CTL,  
  KS_CTL,  
  KI_CTL,  
//  EP_CTL,
  SL_CTL,
};

TAP_STATE_INSTANCE_HOLD(           rs, KC_SLASH, KC_RSFT          );
TAP_STATE_INSTANCE_DUAL(           k5, KC_5,     KC_F5            );
TAP_STATE_INSTANCE_SHIFTED(        kc, KC_C,     KC_LCTL          );
TAP_STATE_INSTANCE_SHIFTED(        kv, KC_V,     KC_LCTL          );
TAP_STATE_INSTANCE_SHIFTED(        kx, KC_X,     KC_LCTL          );
TAP_STATE_INSTANCE_SHIFTED(        kz, KC_Z,     KC_LCTL          );
TAP_STATE_INSTANCE_SHIFTED(        ka, KC_A,     KC_LCTL          );
TAP_STATE_INSTANCE_SHIFTED(        ks, KC_S,     KC_LCTL          );
TAP_STATE_INSTANCE_DOUBLE_SHIFTED( ki, KC_INS,   KC_LALT, KC_LSFT );
//TAP_STATE_INSTANCE_DUAL(           ep, KC_BSLS,  RESET            );
TAP_STATE_INSTANCE_DUAL(           sl, KC_QUOT,  KC_SLEP          );

qk_tap_dance_action_t tap_dance_actions[] = {
  [RS_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,rs_finished, rs_reset),
  [K5_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,k5_finished, k5_reset),
  [KC_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,kc_finished, kc_reset),
  [KV_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,kv_finished, kv_reset),
  [KX_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,kx_finished, kx_reset),
  [KZ_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,kz_finished, kz_reset),
  [KA_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,ka_finished, ka_reset),
  [KS_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,ks_finished, ks_reset),
  [KI_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,ki_finished, ki_reset),
//  [EP_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,ep_finished, ep_reset),
  [SL_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,sl_finished, sl_reset), 
};

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
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

/* NOOP Key and Transparent */
#define KC_     KC_TRNS
#define KC_XXXX KC_NO

#define KSCTL LCTL(KC_LSFT)
#define CTLC  LCTL(KC_C)
#define CTLV  LCTL(KC_V)
#define CTLX  LCTL(KC_X)
#define CTLZ  LCTL(KC_Z)
#define CTLS  LCTL(KC_S)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KEYMAP(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, KC_SPC,  RAISE,                     RAISE,   KC_ENT,  KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = KEYMAP(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, KC_LBRC,                            KC_RBRC, KC_HOME, KC_UP,   KC_END,  KC_MINS, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KSCTL,   KC_LCTL, KC_LALT, KC_NO,   KC_LCBR,                            KC_RCBR, KC_LEFT, KC_DOWN, KC_RGHT, _______, TD(SL_CTL),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, CTLZ,    CTLX,    CTLC,     CTLV,   CTLS,    _______,          _______, KC_BSLS, KC_PGUP, KC_RALT, KC_PGDN, _______, RESET,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  
  [_LOWER] = KEYMAP(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, KC_LBRC,                            KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_BSPC,                   KC_DEL,  _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = KEYMAP(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼── ──────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_SLEP ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, KC_BSLS, RESET,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  
  #ifdef MSV_ONLY
    return msv_only_process(keycode,record);
  #endif

  return true;
}
