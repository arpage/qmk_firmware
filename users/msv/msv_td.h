
#ifndef MSV_TD_H
#define MSV_TD_H

typedef struct {
  bool is_press_action;
  unsigned state;
} tap;

unsigned cur_dance (qk_tap_dance_state_t *state);

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

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
      unregister_code( kc_shift1 ); \
      unregister_code( kc_shift2 ); \
      break; \
  } \
  _##tname##_tap_state.state = 0; \
}

// ... this is hack ...
//
// send "kc_on_single" on a single tap, reset on double tap
//
#define TAP_STATE_RESET(tname, kc_on_single) static tap _##tname##_tap_state = { .is_press_action = true, .state = 0 }; \
void tname##_finished (qk_tap_dance_state_t *state, void *user_data) { \
  _##tname##_tap_state.state = cur_dance(state); \
  switch (_##tname##_tap_state.state) { \
    case SINGLE_TAP:  register_code( kc_on_single ); break; \
    case DOUBLE_TAP: reset_keyboard(); break; \
  } \
} \
void tname##_reset (qk_tap_dance_state_t *state, void *user_data) { \
  switch (_##tname##_tap_state.state) { \
    case SINGLE_TAP:  unregister_code( kc_on_single ); break; \
    case DOUBLE_TAP: break;   \
  } \
  _##tname##_tap_state.state = 0; \
}

// ... this is also hack ...
//
// send "kc_on_single" on a single tap, kc_shift1 then kc on double tap
//
#define TAP_STATE_DUAL_SHIFTED(tname, kc_on_single, kc, kc_shift1) static tap _##tname##_tap_state = { .is_press_action = true, .state = 0 }; \
void tname##_finished (qk_tap_dance_state_t *state, void *user_data) { \
  _##tname##_tap_state.state = cur_dance(state); \
  switch (_##tname##_tap_state.state) { \
    case SINGLE_TAP:  register_code( kc_on_single ); break; \
        case DOUBLE_TAP: \
          register_code( kc_shift1 ); \
          register_code( kc ); \
          break; \
  } \
} \
void tname##_reset (qk_tap_dance_state_t *state, void *user_data) { \
  switch (_##tname##_tap_state.state) { \
    case SINGLE_TAP:  unregister_code( kc_on_single ); break; \
    case DOUBLE_TAP:  \
      unregister_code( kc ); \
      unregister_code( kc_shift1 ); \
      break; \
  } \
  _##tname##_tap_state.state = 0; \
}
#endif
