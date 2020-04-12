
#include "frosty_flake.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

#include "msv.h"
#include "msv_td_actions.h"

enum QFR_layers {
  _RAILWORKS,
  _QWERTY,
  _WOW,
  _LOWER,
  _MOUSE
};

enum QFR_keycodes {
  RAILWORKS = SAFE_RANGE,
  QWERTY,
  WOW,
  LOWER,
  MOUSE
};

enum custom_macros {
  R_PIPE,
  R_POINT
};

const uint16_t PROGMEM fn_actions[] = { //ACTION_LAYER_TAP_TOGGLE requires that number of taps be defined in *config.h* - default set to 5
    [0] = ACTION_LAYER_TAP_KEY(_LOWER, KC_SPC),    //Hold for momentary Lower layer, Tap for Space, 
    [1] = ACTION_LAYER_MOMENTARY(_MOUSE)           //Hold for momentary MOUSE
};

#define LCM(n) LCTL(KC_##n)
#define SPC_LW FUNC(0)
#define MSE FUNC(1)
#define PIPE M(R_PIPE)
#define POINT M(R_POINT)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_RAILWORKS] = KEYMAP_TKL(\
       KC_ESC, KC_F1,       KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,  KC_F12,             KC_T,   KC_1,   KC_2, \
       KC_GRV, KC_1,        KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,  KC_BSPC,   KC_F,   KC_Y,   LSFT(KC_2), \
       KC_TAB, KC_Q,        KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS,   KC_Q,   KC_E,   KC_PENT, \
       SPC_LW,KC_A,         KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,          KC_ENT, \
       KC_LSFT,KC_NUBS,KC_Z,KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,                   KC_W,          \
       KC_LCTL,KC_LGUI,KC_LALT,                KC_SPC,                      KC_RALT /*MSE*/,MSE,    KC_APP,   KC_RCTL,           KC_D,   KC_S,   KC_A
       ),

[_QWERTY] = KEYMAP_TKL(\
       KC_ESC, KC_F1,       KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
       KC_GRV, KC_1,        KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
       KC_TAB, KC_Q,        KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
       SPC_LW,KC_A,         KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,          KC_ENT, \
       KC_LSFT,KC_NUBS,KC_Z,KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,                    KC_UP, \
       KC_LCTL,KC_LGUI,KC_LALT,                KC_SPC,                      KC_RALT /*MSE*/,MSE,    KC_APP,   KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT  
       ),

[_WOW] = KEYMAP_TKL(\
       KC_ESC, KC_F1,       KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,  KC_F12,             KC_7,    KC_8,    KC_9, \
       KC_GRV, KC_1,        KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,  KC_BSPC,   KC_4,    KC_5,    KC_6, \
       KC_TAB, KC_Q,        KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS,   KC_1,    KC_2,    KC_3, \
       SPC_LW,KC_A,         KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,          KC_ENT, \
       KC_LSFT,KC_NUBS,KC_Z,KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,                    KC_UP, \
       KC_LCTL,KC_LGUI,KC_LALT,                KC_SPC,                      KC_RALT /*MSE*/,MSE,    KC_APP,   KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT  
       ),

[_LOWER] = KEYMAP_TKL(\
      RESET,    _______,    _______,   _______, _______,  KC_MPLY,   KC_MSTP,   KC_MPRV,   KC_MNXT,  _______, KC_MUTE, KC_VOLD, KC_VOLU,           QWERTY, RAILWORKS,WOW,  \
      KC_TILD,  KC_EXLM,    KC_AT,     KC_HASH,  KC_DLR,  KC_PERC,   KC_CIRC,   KC_AMPR,   KC_ASTR,  KC_LBRC, KC_RBRC, KC_UNDS, KC_PLUS, KC_DEL,   _______,_______,_______, \
      KC_TAB,   LCM(Q),     LCM(W),    LCM(E),   LCM(R),  XXXXXXX,   XXXXXXX,   KC_HOME,   KC_UP,    KC_END,  XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE,  _______,_______,_______, \
      _______,  LCM(A),     LCM(S),    LCM(D),   LCM(F),  XXXXXXX,   XXXXXXX,   KC_LEFT,   KC_DOWN,  KC_RGHT, XXXXXXX, _______,          _______,                           \
      _______,  XXXXXXX,    LCM(Z),    LCM(X),   LCM(C),  LCM(V),    XXXXXXX,   KC_DEL,    KC_PGUP,  XXXXXXX, KC_PGDN, KC_INS,                    _______,          _______, \
      _______,  _______,    _______,             _______,                       KC_RALT,   _______,  _______, _______,                            _______,_______,_______    \
      ),

[_MOUSE] = KEYMAP_TKL(\
      _______,  _______,   _______,   _______,  _______, _______,   _______,   _______,   _______,  _______, _______, _______, _______,               KC_KP_7,KC_KP_8,KC_KP_9, \
      KC_GRV,   KC_1,      KC_2,      KC_3,     KC_4,    KC_5,      KC_6,      KC_7,      KC_8,     KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,       KC_KP_4,KC_KP_5,KC_KP_6, \
      KC_TAB,   KC_WH_U,   KC_WH_L,   KC_MS_U,  KC_WH_R, XXXXXXX,   XXXXXXX,   KC_BTN3,   KC_BTN4,  KC_BTN5, XXXXXXX, KC_LBRC, KC_RBRC, LALT(KC_PSCR),KC_KP_1,KC_KP_2,KC_KP_3, \
      KC_BSPC,  KC_WH_D,   KC_MS_L,   KC_MS_D,  KC_MS_R, XXXXXXX,   XXXXXXX,   KC_BTN1,   KC_BTN2,  XXXXXXX, XXXXXXX, XXXXXXX,             _______,                            \
      _______,XXXXXXX,PIPE,POINT,     XXXXXXX,  XXXXXXX, XXXXXXX,   XXXXXXX,   KC_CAPS,   _______,  _______,  _______,                     _______,           KC_PENT,         \
      _______,  _______,   _______,             KC_ACL2,                       _______,   MSE,  _______,  _______,                                    _______,_______,_______  \
      )
};

// Macros to send R pointer & dplyr pipe
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    /*switch(id) {
        case R_POINT:
            if (record->event.pressed) { // pointer
                SEND_STRING("->");
            }
            break;
        case R_PIPE:
            if (record->event.pressed) { // dplyr pipe
                SEND_STRING("{\n}\n");
            }
            break;
    }*/
    return MACRO_NONE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case RAILWORKS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_RAILWORKS);
      }
      return false;
      break;
    case WOW:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WOW);
      }
      return false;
      break; 
  }
  #ifdef MSV_ONLY
    return msv_only_process(keycode,record);
  #else
    return true;
  #endif
}


 
 
 
