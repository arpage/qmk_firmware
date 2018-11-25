
#ifndef MSV_ONLY
#define MSV_ONLY 

enum custom_keycodes {
    CBP_MACRO = SAFE_RANGE,
    CTC_MACRO,
    STP_MACRO,
    UNA_MACRO,
    EMA_MACRO,
};

inline bool msv_only_process(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case CBP_MACRO:
                SEND_STRING("B@rK1ng7ar$");
                return false;
            case CTC_MACRO:
                SEND_STRING("1lovectc");
                return false;
            case STP_MACRO:
                SEND_STRING("Panda@2oc");
                return false;
            case UNA_MACRO:
                SEND_STRING("straypacket");
                return false;
            case EMA_MACRO:
                SEND_STRING("straypacket@gmail.com");
                return false;
         }
    }
    return true;
 }
#endif

