/* Copyright 2018 MechMerlin
 * Copyright 2018 Logan Huskins
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "../../../../../users/msv/msv.h"
#include "../../../../../users/msv/msv_td_actions.h"

/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_60_ansi(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_APP, MO(1), KC_LCTL
  ),

  [1] = LAYOUT_60_ansi(
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
    KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_HOME, KC_PGUP, KC_TRNS,
    KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(2), KC_TRNS, KC_TRNS
  ),

  [2] = LAYOUT_60_ansi(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
    BL_TOGG, BL_INC, BL_DEC, BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Keymap: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |CAPS/MO|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |MO  |Ctrl |
   * `-----------------------------------------------------------'
   */
    LAYOUT_60_ansi(
        KC_GESC, KC_1   ,  KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
        KC_TAB ,           KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        LT(MO(1), KC_CAPS),KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT ,
        KC_LSFT,   KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
        KC_LCTL,           KC_LGUI, KC_LALT,           KC_SPC ,           KC_RALT, KC_RGUI,  MO(2)  ,          KC_RCTL),
        
   /* LAYOUT_60_ANSI: (Base Layer) Default Layer */
    LAYOUT_60_ansi(
        KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,   KC_F11 , KC_F12 , KC_DEL ,
        XXXXXXX,          CT(Q),   CT(W),   CT(E),   CT(R),   XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,    XXXXXXX, XXXXXXX, XXXXXXX, LALT(KC_PSCR),
        XXXXXXX,          CT(A),   CT(S),   CT(D),   CT(F),   XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT ,  XXXXXXX, XXXXXXX,          XXXXXXX,
        _______,  CT(Z),   CT(X),   CT(C),   CT(V),   XXXXXXX, KC_INS,  KC_PGUP, KC_NO,   KC_PGDN,   KC_NO,   _______,           
        _______,          XXXXXXX, _______,           XXXXXXX,           _______,   _______,  XXXXXXX,          _______),

   /* LAYOUT_60_ANSI : Third Layer (RGB / Reset) */
    LAYOUT_60_ansi(
        KC_GRV,  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  ,  KC_F10 , KC_F11 , KC_F12 , TD(SL_CTL),
        XXXXXXX,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,  KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, TD(EP_CTL),
        XXXXXXX,          RGB_STA, RGB_BRE, RGB_RAI, RGB_SWI, RGB_SNA, RGB_KNI, RGB_GRA, XXXXXXX,  KC_VOLD, KC_VOLU, KC_MUTE,          XXXXXXX,
        _______,  BL_TOGG , BL_BRTG, BL_INC , BL_DEC, BL_STEP, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, WINTL,   COLMOD,           
        _______,         UNA_MACRO,EMA_MACRO,         CBP_MACRO ,        CTC_MACRO,STP_MACRO,  XXXXXXX,        XXXXXXX),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef MSV_ONLY
  return msv_only_process(keycode,record);
#else
  return true;
#endif
};

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        writePinLow(B1);
    } else {
        writePinHigh(B1);
    }
}
