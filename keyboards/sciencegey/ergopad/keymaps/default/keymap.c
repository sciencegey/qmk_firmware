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
        KC_ESC  ,KC_TAB  ,KC_BSPC ,KC_FN   ,
        KC_NUM  ,KC_PSLS ,KC_PAST ,KC_PMNS ,
        KC_P7   ,KC_P8   ,KC_P9   ,
        KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,
        KC_P1   ,KC_P2   ,KC_P3   ,
        KC_P0   ,KC_EQL ,KC_PDOT ,KC_PENT
    ),
    [_FUNC] = LAYOUT(
        KC_CALC ,KC_LPRN ,KC_RPRN ,_______ ,
        XXXXXXX ,XXXXXXX ,RGB_HUI ,RGB_TOG ,
        XXXXXXX ,XXXXXXX ,RGB_HUD ,
        XXXXXXX ,XXXXXXX ,RGB_SAI ,RGB_VAI ,
        XXXXXXX ,XXXXXXX ,RGB_SAD ,
        XXXXXXX ,XXXXXXX ,XXXXXXX ,RGB_VAD
    )
};
