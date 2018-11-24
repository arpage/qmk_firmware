#ifndef MSV_DZ60_H
#define MSV_DZ60_H

#include "action.h"
#include "quantum.h"

#include "process_keycode/process_tap_dance.h"

#define RGB_STA RGB_M_P //rgb static
#define RGB_BRE RGB_M_B //rgb breathe
#define RGB_RAI RGB_M_R //rgb rainbow
#define RGB_SWI RGB_M_SW //rgb swirl
#define RGB_SNA RGB_M_SN //rgb snake
#define RGB_KNI RGB_M_K //rgb knight
#define RGB_GRA RGB_M_G //rgb gradient

// Make special keycodes more visible
#define ____ KC_TRNS
#define XXXX KC_NO

// Layer definition
enum {
 L0 = 0,
 L1,
 L2,
 L3,
 L4
};

typedef struct {
  bool is_press_action;
  unsigned state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

unsigned cur_dance (qk_tap_dance_state_t *state);

//
// send "kc_on_single" on a single tap, "kc_on_double" on double tap
//
#define TAP_STATE_INSTANCE_DUAL(tname, kc_on_single, kc_on_double) static tap _##tname##_tap_state = { .is_press_action = true, .state = 0 }; \
void tname##_finished (qk_tap_dance_state_t *state, void *user_data) { \
  _##tname##_tap_state.state = cur_dance(state); \
  switch (_##tname##_tap_state.state) { \
    case SINGLE_TAP:  register_code( kc_on_single ); break; \
    case DOUBLE_TAP: register_code( kc_on_double ); break; \
  } \
} \
void tname##_reset (qk_tap_dance_state_t *state, void *user_data) { \
  switch (_##tname##_tap_state.state) { \
    case SINGLE_TAP:  unregister_code( kc_on_single ); break; \
    case DOUBLE_TAP: unregister_code( kc_on_double ); break;   \
  } \
  _##tname##_tap_state.state = 0; \
}

//
// send "kc" on a single tap, "kc_on_hold" when held
//
#define TAP_STATE_INSTANCE_HOLD(tname, kc_on_single, kc_on_hold) static tap _##tname##_tap_state = { .is_press_action = true, .state = 0 }; \
void tname##_finished (qk_tap_dance_state_t *state, void *user_data) { \
  _##tname##_tap_state.state = cur_dance(state); \
  switch (_##tname##_tap_state.state) { \
    case SINGLE_TAP:  register_code( kc_on_single ); break; \
    case SINGLE_HOLD: register_code( kc_on_hold ); break; \
  } \
} \
void tname##_reset (qk_tap_dance_state_t *state, void *user_data) { \
  switch (_##tname##_tap_state.state) { \
    case SINGLE_TAP:  unregister_code( kc_on_single ); break; \
    case SINGLE_HOLD: unregister_code( kc_on_hold ); break;   \
  } \
  _##tname##_tap_state.state = 0; \
}

//
// send "kc" on a single tap, "kc_shifted" then "kc" on double tap
//
#define TAP_STATE_INSTANCE_SHIFTED(tname, kc, kc_shifted) static tap _##tname##_tap_state = { .is_press_action = true, .state = 0 }; \
void tname##_finished (qk_tap_dance_state_t *state, void *user_data) { \
  _##tname##_tap_state.state = cur_dance(state); \
  switch (_##tname##_tap_state.state) { \
    case SINGLE_TAP:  register_code( kc ); break; \
    case DOUBLE_TAP: \
      register_code( kc_shifted ); \
      register_code( kc ); \
  } \
} \
void tname##_reset (qk_tap_dance_state_t *state, void *user_data) { \
  switch (_##tname##_tap_state.state) { \
    case SINGLE_TAP:  unregister_code( kc ); break; \
    case DOUBLE_TAP:  \
      unregister_code( kc ); \
      unregister_code( kc_shifted ); \
      break; \
  } \
  _##tname##_tap_state.state = 0; \
}

//
// send "kc" on a single tap, "kc_shifted" then "kc" on double tap
//
#define TAP_STATE_INSTANCE_DOUBLE_SHIFTED(tname, kc, kc_shift1, kc_shift2) static tap _##tname##_tap_state = { .is_press_action = true, .state = 0 }; \
void tname##_finished (qk_tap_dance_state_t *state, void *user_data) { \
  _##tname##_tap_state.state = cur_dance(state); \
  switch (_##tname##_tap_state.state) { \
    case SINGLE_TAP:  register_code( kc ); break; \
    case DOUBLE_TAP: \
      register_code( kc_shift1 ); \
      register_code( kc_shift2 ); \
      register_code( kc ); \
  } \
} \
void tname##_reset (qk_tap_dance_state_t *state, void *user_data) { \
  switch (_##tname##_tap_state.state) { \
    case SINGLE_TAP:  unregister_code( kc ); break; \
    case DOUBLE_TAP:  \
      unregister_code( kc ); \
      unregister_code( kc_shift2 ); \
      unregister_code( kc_shift1 ); \
      break; \
  } \
  _##tname##_tap_state.state = 0; \
}

#endif
