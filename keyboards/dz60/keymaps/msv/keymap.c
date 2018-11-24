#include QMK_KEYBOARD_H

#include "dz60.h"
#include "msv.h"
#include "msv_only.h"

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
TAP_STATE_INSTANCE_DUAL(           sl, KC_BSPC,  KC_SLEP          );

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

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define NA_____ KC_NO

#define CT(k) LCTL(KC_##k)

#define RGB_STA RGB_M_P //rgb static
#define RGB_BRE RGB_M_B //rgb breathe
#define RGB_RAI RGB_M_R //rgb rainbow
#define RGB_SWI RGB_M_SW //rgb swirl
#define RGB_SNA RGB_M_SN //rgb snake
#define RGB_KNI RGB_M_K //rgb knight
#define RGB_GRA RGB_M_G //rgb gradient

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
#else   -   
  return true;
#endif
};
