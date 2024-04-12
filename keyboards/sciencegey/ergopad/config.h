/*
Copyright 2023 Sam Knowles/sciencegey

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// // wiring of each half
// #define MATRIX_ROW_PINS { GP2, GP3, GP4, GP5, GP6, GP7, GP8 }  // Top to bottom
// #define MATRIX_COL_PINS { GP27, GP26, GP18, GP20, GP19, GP10, GP9 }  // Left to right

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#ifdef RGBLIGHT_ENABLE
    #define WS2812_PIO_USE_PIO1
    // #define RGB_MATRIX_LED_COUNT 86   // Number of LEDs
    // // #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
    // // #define RGB_MATRIX_SPLIT
    // #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_ALL
    #define RGBLIGHT_DEFAULT_HUE 249
    #define RGBLIGHT_DEFAULT_SAT 255
#endif

/* Double-tap reset boot-loader entry */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Specify a optional status led by GPIO number which blinks when entering the bootloader

// /* disable debug print */
// #define NO_DEBUG

// /* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
