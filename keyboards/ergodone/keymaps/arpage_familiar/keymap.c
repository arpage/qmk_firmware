#define LEADER_TIMEOUT 500
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// Layers
/*
#define BASE 0 // default layer
#define SYMB 1 // international symbols
#define CSYM 2 // international symbols shifted
#define CSYM 2 // international symbols shifted
#define NUMP 3 // numpad
#define ARRW 4 // function, media, arrow keys
*/
enum keylayers {
BASE = 0,
NUMP,
ARRW
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// 
//op#define MV()


// Tap Dancing
void dance_lock (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) { // Press once for NUMLOCK
        register_code (KC_NLCK);
        unregister_code (KC_NLCK);
    } else if (state->count == 2) { // Press twice for CAPSLOCK
        register_code (KC_CAPS);
        unregister_code (KC_CAPS);
    } else if (state->count == 3) { //Press thrice for SCROLLLOCK
        register_code (KC_SLCK);
        unregister_code (KC_SLCK);
    }
}
enum {LOCKS = 0};
qk_tap_dance_action_t tap_dance_actions[] = {
    [LOCKS] = ACTION_TAP_DANCE_FN(dance_lock)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* layer 0 : default
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | `      |   1  |   2  |   3  |   4  |   5  |   6  |           |  7   |   8  |   9  |   0  |   -  |   =  | BCKSPC |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  | HOME |           | PGUP |   Y  |   U  |   I  |   O  |   P  | DELETE |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | '      |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  ENTER |
 * |--------+------+------+------+------+------|  END |           | PGDN |------+------+------+------+------+--------|
 * | (/LSFT |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  UP  | )/RSFT |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * | LCTRL  | LGUI | MENU | LEAD | Enter|                                       |[/RALT|]/RCTL| LEFT | DOWN |  RIGHT |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |PRTSCR| ESC  |       | VOL- | VOL+ |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |SLASH/| Locks|       | MUTE |WHACK\|      |
 *                                 |  SPC |NUMP\M|------|       |------|ARRW\M| SPC  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
        // left hand
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_HOME,
        KC_QUOT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_END,
        KC_LCTL,    KC_LGUI,    KC_LALT,    KC_LEAD,    KC_ENTER,
                                                                    KC_PSCR,    KC_ESC,
                                                                                TD(LOCKS),
                                                KC_SPC,     LT(NUMP, KC_SLSH),  _______,
        // right hand
            KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,
            KC_PGUP,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL,
                        KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENTER,
            KC_PGDN,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_UP,      KC_RSFT,
                        KC_LBRC,    KC_RBRC,    KC_LEFT,    KC_DOWN,    KC_RGHT,
            KC_VOLD,    KC_VOLU,
            KC_MUTE,
            _______,   LT(ARRW, KC_BSLS),   KC_SPC
    ),
    
/* layer 3: numberpad
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |      |      |      |      |      |      |           |      |      |   (  |   )  |   /  |  *   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |  -   |INSERT  |
 * |--------+------+------+------+------+------|      |           |CtlTab|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |  +   |        |
 * |--------+------+------+------+------+------|      |           |CtlSft|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |Tab  |      |   1  |   2  |   3  |  =   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * |        |      |      |      |      |                                       |0/RALT|./RCTL|   ,  | ENTER|        |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUMP] = LAYOUT_ergodox(
        // left hand
        KC_ESC,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                            XXXXXXX,    XXXXXXX,
                                                        XXXXXXX,
                            XXXXXXX,        XXXXXXX,    XXXXXXX,
        // right hand
            XXXXXXX,               XXXXXXX,                S(KC_9),    S(KC_0),    KC_PSLS,    KC_PAST,    XXXXXXX,
            LCTL(KC_TAB),          XXXXXXX,                KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_PMNS,    KC_INS,
                                   XXXXXXX,                KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_PPLS,    XXXXXXX,
            LCTL(LSFT(KC_TAB)),    XXXXXXX,                KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_PEQL,    XXXXXXX,
                                   MT(MOD_RALT, KC_KP_0),  MT(MOD_RCTL, KC_KP_DOT),KC_PCMM,    KC_PENT,    XXXXXXX,
            XXXXXXX,    XXXXXXX,
            XXXXXXX,
            XXXXXXX,    XXXXXXX,    XXXXXXX
    ),
/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESCAPE |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Play   | Stop |      |      |      |      |CtlTab|           |      |      |      |      |      |      | INSERT |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Next   |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|CtlSft|           |      |------+------+------+------+------+--------|
 * | Prev   |MS U  |BTN1  |      |      |      |Tab   |           |      |      |      |      |      | PGUP |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * | MS L   | MS D | MS R | BTN2 | BTN3 |                                       |      |      | HOME | PGDN |    END |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | SYSRQ| PAUSE|       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[ARRW] = LAYOUT_ergodox(
        // left hand
        KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,
        KC_MPLY,    KC_MSTP,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    LCTL(KC_TAB),
        KC_MPRV,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        KC_MNXT,    KC_MS_U,    KC_BTN1,    XXXXXXX,    XXXXXXX,    XXXXXXX,    LCTL(LSFT(KC_TAB)),
        KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_BTN2,    KC_BTN3,
                                                                    KC_SYSREQ,  KC_PAUSE,
                                                                                XXXXXXX,
                                                    XXXXXXX,        XXXXXXX,    XXXXXXX,
        // right hand
            KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     XXXXXXX,
            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_INS,
                        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_PGUP,    XXXXXXX,
                                    XXXXXXX,    XXXXXXX,    KC_HOME,    KC_PGDN,    KC_END,
            XXXXXXX,    XXXXXXX,
            XXXXXXX,
            XXXXXXX,    XXXXXXX,    XXXXXXX
    ),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    //set_unicode_input_mode(UC_LNX); // Linux
    //set_unicode_input_mode(UC_OSX); // Mac OSX
    //set_unicode_input_mode(UC_WIN); // Windows (with registry key, see wiki)
    //set_unicode_input_mode(UC_WINC); // Windows (with WinCompose, see wiki)
};

LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {    
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        SEQ_ONE_KEY(KC_1) {      
            register_code(KC_LSFT);
            register_code(KC_LALT);
            register_code(KC_INS);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            unregister_code(KC_INS);
        }
        SEQ_ONE_KEY(KC_2) {      
            register_code(KC_LSFT);
            register_code(KC_LCTL);
            register_code(KC_I);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            unregister_code(KC_I);
        }    
        SEQ_TWO_KEYS(KC_O,KC_P) {      
            register_code(KC_LGUI);
            register_code(KC_X);
            unregister_code(KC_LGUI);
            unregister_code(KC_X);
            register_code(KC_U);
            unregister_code(KC_U);
            register_code(KC_S);
            unregister_code(KC_S);
        }
    }
};

void led_set_user(uint8_t usb_led) {

    uint8_t layer = biton32(layer_state);
    
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case NUMP:
            ergodox_right_led_1_on();
            break;
        case ARRW:
            ergodox_right_led_2_on();
            break;
        default:
           if (usb_led & (1<<USB_LED_NUM_LOCK)) {
               ergodox_right_led_1_on();
           } else {
               ergodox_right_led_1_off();
           }
           if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
               ergodox_right_led_2_on();
           } else {
               ergodox_right_led_2_off();
           }
           if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
               ergodox_right_led_3_on();
           } else {
               ergodox_right_led_3_off();
           }
           break;
        }


}
