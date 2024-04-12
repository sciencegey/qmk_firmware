/* Copyright 2023 Sam Knowles/sciencegey
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "ergopad.h"

#define MATRIX_MASKED
const matrix_row_t matrix_mask[MATRIX_ROWS] =
{
    0b00001111,
    0b00001111,
    0b00001110,
    0b00001111,
    0b00001110,
    0b00001111
};

// How long (in milliseconds) to wait between animation steps for each of the "Solid color breathing" animations
const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {50, 50, 50, 50};
