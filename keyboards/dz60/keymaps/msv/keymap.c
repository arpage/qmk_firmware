
#include QMK_KEYBOARD_H
#include "msv.h"
#include "msv_td_actions.h"

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
    KEYMAP(
        KC_GESC, KC_1   ,  KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , NA_____, KC_BSPC,
        KC_TAB ,           KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        LT(MO(1), KC_CAPS),KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT ,
        KC_LSFT, NA_____,  KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,          NA_____,
        KC_LCTL,           KC_LGUI, KC_LALT, NA_____,          KC_SPC ,          NA_____, KC_RALT, KC_RGUI, NA_____, MO(2)  ,          KC_RCTL),
        
   /* Keymap: (Base Layer) Default Layer
   */
    KEYMAP(
        KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,   KC_F11 , KC_F12 , NA_____, KC_DEL ,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,    XXXXXXX, XXXXXXX, XXXXXXX, LALT(KC_PSCR),
        XXXXXXX,          KC_LCTL, KC_LSFT, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT ,  XXXXXXX, XXXXXXX,          XXXXXXX,
        _______, NA_____, XXXXXXX,XXXXXXX,TD(KI_CTL),XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  KC_PGUP, KC_PGDN,   KC_INS, _______,           NA_____,
        _______,          XXXXXXX, _______, NA_____,          XXXXXXX,          NA_____, _______,   _______, NA_____, XXXXXXX,          _______),

   /* Keymap : Third Layer (RGB / Reset)
   */
    KEYMAP(
        KC_ESC,  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  ,  KC_F10 , KC_F11 , KC_F12 , NA_____, TD(SL_CTL),
        XXXXXXX,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
        XXXXXXX,          RGB_STA, RGB_BRE, RGB_RAI, RGB_SWI, RGB_SNA, RGB_KNI, RGB_GRA, XXXXXXX,  KC_MPRV, KC_MPLY, KC_MNXT,          XXXXXXX,
        _______, NA_____, BL_DEC , BL_TOGG, BL_INC , BL_STEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_VOLD, KC_VOLU, KC_MUTE,          NA_____,
        _______,         UNA_MACRO,EMA_MACRO, NA_____,        CBP_MACRO ,       NA_____, CTC_MACRO,STP_MACRO, NA_____, XXXXXXX,        XXXXXXX),
 
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef MSV_ONLY
  return msv_only_process(keycode,record);
#else
  return true;
#endif
};
