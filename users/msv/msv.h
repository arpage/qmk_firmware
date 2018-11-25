#ifndef MSV_DZ60_H
#define MSV_DZ60_H

#include "action.h"
#include "quantum.h"
#include "process_keycode/process_tap_dance.h"
#include "msv_only.h"
#include "msv_td.h"

#define CT(k) LCTL(KC_##k)

// Make special keycodes more visible
#define ____    KC_TRNS
#define XXXX    KC_NO
#define NA__    KC_NO
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define NA_____ KC_NO

#define RGB_STA RGB_M_P //rgb static
#define RGB_BRE RGB_M_B //rgb breathe
#define RGB_RAI RGB_M_R //rgb rainbow
#define RGB_SWI RGB_M_SW //rgb swirl
#define RGB_SNA RGB_M_SN //rgb snake
#define RGB_KNI RGB_M_K //rgb knight
#define RGB_GRA RGB_M_G //rgb gradient

// Layer definition
enum msv_layer_defs {
 L0 = 0,
 L1,
 L2,
 L3,
 L4
};

//
// try a visual layout for the ergodone
//
#define MSV_ERGO_KC_KEYMAP(                                       \
    k00,k01,k02,k03,k04,k05,k06,      k07,k08,k09,k0A,k0B,k0C,k0D,\
    k10,k11,k12,k13,k14,k15,k16,      k17,k18,k19,k1A,k1B,k1C,k1D,\
    k20,k21,k22,k23,k24,k25,              k28,k29,k2A,k2B,k2C,k2D,\
    k30,k31,k32,k33,k34,k35,k36,      k37,k38,k39,k3A,k3B,k3C,k3D,\
    k40,k41,k42,k43,k44,                      k49,k4A,k4B,k4C,k4D,\
                            k55,k56,  k57,k58,                    \
                                k54,  k59,                        \
                        k53,k52,k51,  k5C,k5B,k5A )               \
   {                                                              \
    { k00,   k01, k02, k03, k04, k05,   k06,      k07,   k08,   k09, k0A, k0B, k0C, k0D    }, \
    { k10,   k11, k12, k13, k14, k15,   k16,      k17,   k18,   k19, k1A, k1B, k1C, k1D    }, \
    { k20,   k21, k22, k23, k24, k25,   KC_NO,    KC_NO, k28,   k29, k2A, k2B, k2C, k2D    }, \
    { k30,   k31, k32, k33, k34, k35,   k36,      k37,   k38,   k39, k3A, k3B, k3C, k3D    }, \
    { k40,   k41, k42, k43, k44, KC_NO, KC_NO,    KC_NO, KC_NO, k49, k4A, k4B, k4C, k4D    }, \
    { KC_NO, k51, k52, k53, k54, k55,   k56,      k57,   k58,   k59, k5A, k5B, k5C, KC_NO  } \
   }

#define MSV_ERGO_KC_LAYOUT_ergodox MSV_ERGO_KC_KEYMAP

#endif
