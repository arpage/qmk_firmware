/* Copyright 2018 MechMerlin
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
#include "msv.h"
#include "msv_td_actions.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
      L1CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(2),
      KC_NO,   KC_LCTL, KC_LALT,                   KC_SPACE,                 MO(3), KC_RGUI, KC_NO
  ),

  [1] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS, KC_DEL,
 LALT(KC_TAB), CT(Q),   CT(W),   CT(E),   CT(R),   KC_NO,   KC_NO,   KC_HOME, KC_UP, TD(CO_CTL),KC_NO,   KC_NO,   KC_NO, KC_PSCR,
      KC_TRNS, CT(A),   CT(S),   CT(D),   CT(F),   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO,   KC_LWIN,
      KC_TRNS, CT(Z),   CT(X),   CT(C),   CT(V),   KC_NO,   KC_INS,  KC_PGUP, KC_NO,   KC_PGDN, KC_NO,   KC_NO,   KC_TRNS,
      KC_NO,  KC_TRNS, KC_TRNS,                    CBP_MACRO,                          CTC_MACRO, STP_MACRO,KC_NO
  ),
  
  [2] = LAYOUT(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, TD(KI_CTL), TD(SL_CTL),
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, TD(EP_CTL),
      KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LWIN,
      KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   WINTL,   COLMOD,  KC_TRNS,
      KC_NO,   KC_NO,   KC_NO,                     KC_SPACE,                           KC_TRNS, KC_NO, KC_NO
  ),
  
  [3] = LAYOUT(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, TD(KI_CTL), TD(SL_CTL),
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_UP,   KC_END,  KC_NO,   LCTL(KC_R),     LCTL(KC_O), LCTL(KC_X),
      KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_NO, LCTL(KC_Z),LCTL(KC_V),     LCTL(KC_C),
      KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LCTL, LSFT(KC_TAB),   KC_TAB,  KC_LALT,
      KC_NO,   KC_TRNS, KC_NO,                     KC_SPACE,                           KC_TRNS, KC_TRNS, KC_NO
   ),
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef MSV_ONLY
  return msv_only_process(keycode,record);
#else
  return true;
#endif
}

