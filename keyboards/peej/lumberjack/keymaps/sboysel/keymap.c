/* Copyright 2015-2021 Jack Humbert
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

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_ortho_5x12(
    KC_TILD,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_ESC,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    MO(3),       KC_LCTL, KC_LALT, KC_LCMD, MO(1),   KC_SPC,  KC_SPC,  MO(2),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
[1] = LAYOUT_ortho_5x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WSCH, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT
),
[2] = LAYOUT_ortho_5x12(
    KC_TILD,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_TILD,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_CANCEL, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, _______,
    _______,   _______, KC_CUT,  KC_COPY, KC_PSTE, _______, _______, _______, _______, _______, _______, _______,
    _______,   _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),
[3] = LAYOUT_ortho_5x12(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, QK_BOOT, DB_TOGG, EE_CLR, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
    _______, _______, MU_NEXT, AU_ON,  AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
    KC_CAPS, AU_PREV, AU_NEXT, MU_ON,  MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};
