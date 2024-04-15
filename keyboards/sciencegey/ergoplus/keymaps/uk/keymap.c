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
        KC_TAB   ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_FN                             ,KC_FN   ,KC_Y    ,KC_U    ,KC_I    ,KC_O     ,KC_P     ,KC_ALGR ,
        KC_CAPS  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_LBRC                           ,KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L     ,KC_SCLN  ,KC_QUOT ,
        KC_LSFT  ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B                ,KC_HOME ,KC_PGUP               ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT   ,KC_SLSH  ,KC_NUHS ,
        KC_LCTL  ,KC_LWIN ,KC_LALT ,KC_APP  ,KC_NUBS                                                               ,KC_RSFT ,KC_LEFT ,KC_DOWN  ,KC_UP    ,KC_RIGHT,
                                                        KC_SPACE ,KC_BSPC ,KC_END  ,KC_PGDN ,KC_DEL ,KC_ENT
    ),
    [_FUNC] = LAYOUT(
        XXXXXXX  ,RGB_VAI ,RGB_MOD ,RGB_TOG ,RGB_HUI ,RGB_SAI ,XXXXXXX                           ,XXXXXXX ,XXXXXXX ,KC_MPRV ,KC_MPLY ,KC_MSTP  ,KC_MNXT  ,KC_MUTE ,
        XXXXXXX  ,RGB_M_P ,RGB_M_B ,RGB_M_R ,RGB_M_SW ,RGB_M_TW ,XXXXXXX                         ,_______ ,_______ ,_______ ,_______ ,_______  ,_______  ,KC_VOLU ,
        XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______                           ,_______ ,_______ ,_______ ,_______ ,_______  ,_______  ,KC_VOLD ,
        _______  ,_______ ,_______ ,_______ ,_______ ,_______ ,_______                           ,_______ ,_______ ,_______ ,_______ ,_______  ,_______  ,_______ ,
        _______  ,_______ ,_______ ,_______ ,_______ ,_______                 ,_______ ,_______           ,_______ ,_______ ,_______ ,_______  ,_______  ,_______ ,
        QK_RBT   ,_______ ,_______ ,_______ ,EE_CLR                                                                ,EE_CLR   ,_______ ,_______  ,_______  ,QK_RBT  ,
                                                            _______  ,_______ ,_______ ,_______  ,_______ ,_______
    )
};

const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {21, 1, HSV_RED}    // LED 21 is the caps lock key, make it bright red
);

const rgblight_segment_t PROGMEM function_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 27, HSV_OFF},       // Blank the whole keyboard
    {43, 27, HSV_OFF},       // Blank the whole keyboard
    {1, 1, HSV_TEAL},       // Brightness
    {2, 1, HSV_TEAL},       // Mode
    {3, 1, HSV_TEAL},       // Toggle
    {4, 1, HSV_TEAL},       // Hue
    {5, 1, HSV_TEAL},       // Saturation
    {8, 1, 127, 255, 255},  // Plain
    {9, 1, 174, 255, 255},  // Breathe
    {10, 1, 42, 255, 255},  // Rainbow
    {11, 1, 0, 255, 255},   // Swirl
    {12, 1, 230, 255, 255}, // Twinkle

    {20, 1, HSV_WHITE},     // Function key (left)
    {63, 1, HSV_WHITE},     // Function key (right)

    {43, 1, HSV_ORANGE},    // Mute
    {50, 1, HSV_ORANGE},    // Vol up
    {57, 1, HSV_ORANGE},    // Vol down

    {44, 4, HSV_CYAN},      // Media controls

    {35, 1, HSV_BLUE},      // Reboot
    {39, 1, HSV_RED},       // Reset EEPROM
    {78, 1, HSV_BLUE},      // Reboot
    {82, 1, HSV_RED}        // Reset EEPROM
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    capslock_layer,
    function_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

bool led_update_user(led_t led_state) {
    // Controls the caps lock layer based on the "real" caps lock light
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Lights up the various keys on the function layer
    rgblight_set_layer_state(1, layer_state_cmp(state, _FUNC));
    return state;
}
