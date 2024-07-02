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
#include "muse.h"
#include "evantravers.h"
/* #include "rev3_drop.h" */

#define LAYOUT_preonic_2x2u_wrapper(...) LAYOUT_preonic_2x2u(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_preonic_2x2u_wrapper(
  ESC_F19, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TO(_QWERTY),
  TAB_GSK, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_LCTL, KC_LGUI, SYMBL,   KC_LALT,          KC_SPC,  KC_TAB,           KC_ESC,  CNTRL,   KC_RGUI, KC_RCTL
),

[_GAMING2] = LAYOUT_preonic_2x2u_wrapper(
  KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_PGUP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_PGDN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
),

[_QWERTY] = LAYOUT_preonic_2x2u_wrapper(
  ESC_F19, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TO(_GAMING),
  _________________QWERTY_L1_________________, _______, _______, _________________QWERTY_R1_________________,
  _________________QWERTY_L2_________________, _______, _______, _________________QWERTY_R2_________________,
  _________________QWERTY_L3_________________, _______, _______, _________________QWERTY_R3_________________,
  _______,  _______, ______LH_THUMBS______, ______RH_THUMBS______, _______, _______
),

[_SYMBL] = LAYOUT_preonic_2x2u_wrapper(
  KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _________________SYMBL_L1__________________, _______, _______, _________________SYMBL_R1__________________,
  _________________SYMBL_L2__________________, _______, _______, _________________SYMBL_R2__________________,
  _________________SYMBL_L3__________________, _______, _______, _________________SYMBL_R3__________________,
  _______,  _______, ____LH_THUMBS_SYM____, ____RH_THUMBS_SYM____, _______, _______
),

[_CNTRL] = LAYOUT_preonic_2x2u_wrapper(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  _________________CNTRL_L1__________________, _______, _______, _________________CNTRL_R1__________________,
  _________________CNTRL_L2__________________, _______, _______, _________________CNTRL_R2__________________,
  _________________CNTRL_L3__________________, _______, _______, _________________CNTRL_R3__________________,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_preonic_2x2u_wrapper(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _________________ADJUST_L1_________________, _______, _______, _________________ADJUST_R1_________________,
  _________________ADJUST_L2_________________, _______, _______, _________________ADJUST_R2_________________,
  _________________ADJUST_L3_________________, _______, _______, _________________ADJUST_R3_________________,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_SHORTCUTS] = LAYOUT_preonic_2x2u_wrapper(
  KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
  _______________SHORTCUTS_L1________________, _______, _______, _______________SHORTCUTS_R1________________,
  _______________SHORTCUTS_L2________________, _______, _______, _______________SHORTCUTS_R2________________,
  _______________SHORTCUTS_L3________________, _______, _______, _______________SHORTCUTS_R3________________,
  _______,  _______, ____LH_THUMBS_SHT____, ____RH_THUMBS_SHT____, _______, _______
),

};
