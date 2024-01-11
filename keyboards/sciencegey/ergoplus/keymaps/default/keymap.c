#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _FUNC,
};

#define KC_FN MO(_FUNC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_ESC   ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6                             ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11   ,KC_F12   ,KC_CALC ,
        KC_GRAVE ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6                              ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINUS ,KC_EQUAL ,KC_INS  ,
        KC_TAB   ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_FN                             ,KC_FN   ,KC_Y    ,KC_U    ,KC_I    ,KC_O     ,KC_P     , ,
        KC_CAPS  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_LBRC                           ,KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L     ,KC_SCLN  ,KC_QUOT ,
        KC_LSFT  ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B                    ,KC_HOME ,KC_PGUP           ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT   ,KC_SLSH  ,KC_NUHS ,
        KC_LCTL  ,KC_LWIN ,KC_LALT ,KC_APP  ,KC_NUBS                                                               ,KC_RSFT ,KC_LEFT ,KC_DOWN  ,KC_UP    ,KC_RIGHT,
                                                            KC_SPACE ,KC_BSPC ,KC_END  ,KC_PGDN ,KC_DEL ,KC_ENT
    ),
    [_FUNC] = LAYOUT(
        XXXXXXX  ,RGB_VAI ,RGB_MOD ,RGB_TOG ,RGB_HUI ,RGB_SAI ,XXXXXXX                           ,XXXXXXX ,XXXXXXX ,KC_MPRV ,KC_MPLY ,KC_MSTP  ,KC_MNXT  ,KC_MUTE ,
        XXXXXXX  ,RGB_M_P ,RGB_M_B ,RGB_M_R ,RGB_M_SW ,RGB_M_TW ,XXXXXXX                         ,_______ ,_______ ,_______ ,_______ ,_______  ,_______  ,KC_VOLU ,
        XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                           ,_______ ,_______ ,_______ ,_______ ,_______  ,_______  ,KC_VOLD ,
        _______  ,_______ ,_______ ,_______ ,_______ ,_______ ,_______                           ,_______ ,_______ ,_______ ,_______ ,_______  ,_______  ,_______ ,
        _______  ,_______ ,_______ ,_______ ,_______ ,_______                 ,_______ ,_______           ,_______ ,_______ ,_______ ,_______  ,_______  ,_______ ,
        _______  ,_______ ,_______ ,_______ ,_______                                                               ,_______ ,_______ ,_______  ,_______  ,_______ ,
                                                            _______  ,_______ ,_______ ,_______  ,_______ ,_______
    )
};

// #ifdef RGB_MATRIX_ENABLE
//     led_config_t g_led_config = { {
//     // Key Matrix to LED Index
//     //     // left hand
//     // {0   ,   1   ,    2  ,   3   ,   4   ,   5   ,   6 },
//     // {7   ,   8   ,    9  ,   10  ,   11  ,   12  ,   13},
//     // {14  ,   15  ,    16 ,   17  ,   18  ,   19  ,   20},
//     // {21  ,   22  ,    23 ,   24  ,   25  ,   26  ,   27},
//     // {33  ,   32  ,    31 ,   30  ,   29  ,   29  ,   28},
//     //     // right hand
//     // {35  ,   36  ,    37 ,   38  ,   39  ,   40  ,   41, 42,},
//     // {50  ,   49 ,    48  ,   47  ,   46  ,   46  ,   44, 43,},
//     // {51  ,   52  ,   53  ,   54  ,   55  ,   56  ,   57, 58,},
//     // {66  ,   65  ,   64  ,   63  ,   62  ,   61  ,   60, 59,},
//     // {67  ,   68  ,   69  ,   70  ,   71  ,   72  ,   73, 74}
//     // Left hand
//     { 0, 1, 2, 3, 4, 5, 6 },
//     { 14, 15, 16, 17, 18, 19, 20 },
//     { 28, 29, 30, 31, 32, 33, 34 },
//     { 42, 43, 44, 45, 46, 47, 48 },
//     { 56, 57, 58, 59, 60, 61, 62 },
//     { 70, 71, 72, 73, 74, NO_LED, NO_LED },
//     { NO_LED, NO_LED, NO_LED, NO_LED, 80, 81, 82 },
//     // Right hand
//     { 7, 8, 9, 10, 11, 12, 13 },
//     { 21, 22, 23, 24, 25, 26, 27 },
//     { 35, 36, 37, 38, 39, 40, 41 },
//     { 49, 50, 51, 52, 53, 54, 55 },
//     { 63, 64, 65, 66, 67, 68, 69 },
//     { NO_LED, NO_LED, 75, 76, 77, 78, 79 },
//     { 83, 84, 85, NO_LED, NO_LED, NO_LED, NO_LED }


//     },
//     {
//     // LED Index to Physical Position
//         // left hand
//     {224,64}, {208,64}, {192,64},{176,64}, {160,64}, {144,64},{128,64},
//     {224,53}, {208,53}, {192,53},{176,53}, {160,53}, {144,53},{128,53},
//     {224,43}, {208,43}, {192,43},{176,43}, {160,43}, {144,43},{128,43},
//     {224,32}, {208,32}, {192,32},{176,32}, {160,32}, {144,32},{128,32},
//     {128,21}, {144,21}, {160,21},{176,21}, {192,21}, {208,21},{224,21},
//         // right hand
//     {112,64},{ 96,64},{ 80,64},{ 64,64},{ 48,64},{ 32,64},{024,64},{016,64},
//     {112,53},{ 96,53},{ 80,53},{ 64,53},{ 48,53},{ 32,53},{024,53},{016,53},
//     {112,64},{ 96,43},{ 80,43},{ 64,43},{ 48,43},{ 32,43},{024,43},{016,43},
//     {112,64},{ 96,32},{ 80,32},{ 64,32},{ 48,32},{ 32,32},{024,32},{016,32},
//     {112,64},{ 96,21},{ 80,21},{ 64,21},{ 48,21},{ 32,21},{024,21},{016,21}

//     }, {
//     // LED Index to Flag
//     4,4,4,4,4,4,4,   4,4,4,4,4,4,4,4,
//     4,4,4,4,4,4,4,   4,4,4,4,4,4,4,4,
//     4,4,4,4,4,4,4,   4,4,4,4,4,4,4,4,
//     4,4,4,4,4,4,4,   4,4,4,4,4,4,4,4,
//     4,4,4,4,4,4,4,   4,4,4,4,4,4,4,4
//     } };
// #endif
