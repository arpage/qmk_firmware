
#ifndef MSV_TD_ACTIONS_H
#define MSV_TD_ACTIONS_H


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
  EP_CTL,
  SL_CTL,
  AP_CTL,
  CO_CTL,
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
TAP_STATE_RESET(                   ep, KC_DEL                     );
TAP_STATE_INSTANCE_DUAL(           sl, KC_DEL,   KC_SLEP          );
TAP_STATE_INSTANCE_DUAL(           ap, KC_BSLS,  KC_PSCR          );
TAP_STATE_DUAL_SHIFTED(            co, KC_END,   KC_O,    KC_LCTL );

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
  [EP_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,ep_finished, ep_reset),
  [SL_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,sl_finished, sl_reset), 
  [AP_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,ap_finished, ap_reset),   
  [CO_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,co_finished, co_reset),   
  
};

#define OS_CTL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_SHA OSM(MOD_LSFT)       
#define L1CAPS  LT(1,KC_CAPS)       //
#define WINTL  LGUI(KC_GRAVE)      // ConEmu Restart Window
#define COLMOD LALT(LSFT(KC_INS))  // PHPStorm Column Edit Mode

#endif
