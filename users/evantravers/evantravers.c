/*
Copyright 2019 Evan Travers <evantravers@gmail.com> @evantravers

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

#include "evantravers.h"
#include QMK_KEYBOARD_H

uint32_t user_key_timer;

tap_dance_action_t tap_dance_actions[] = {
  [TD_TAB_ESC]     = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
  [TD_PREV_NEXT]   = ACTION_TAP_DANCE_DOUBLE(KC_MFFD, KC_MRWD),
  [TD_SCRNST]      = ACTION_TAP_DANCE_DOUBLE(LGUI(LSFT(LCTL(KC_4))), LGUI(LSFT(KC_4))),
  [TD_MUTE]        = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_GRV), LGUI(LSFT(KC_M))),
  [TD_DWNMUTE]     = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE),
};

#if defined(COMBO_ENABLE)
const uint16_t PROGMEM apos_combo[] = {RALT_T(KC_L), RGUI_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM hyper_combo[] = {LGUI_T(KC_A), RGUI_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM spc_combo[] = {KC_E, LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM ret_combo[] = {KC_Z, KC_X, COMBO_END};
combo_t key_combos[] = {
    COMBO(apos_combo, KC_QUOT),
    COMBO(hyper_combo, KC_F19),
    COMBO(esc_combo, KC_ESC),
    COMBO(spc_combo, KC_SPC),
    COMBO(ret_combo, KC_ENT),
};
#endif

#ifdef AUDIO_ENABLE
float gaming[][2] = SONG(AG_SWAP_SOUND);
float qwerty[][2] = SONG(UNICODE_LINUX);
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TO(_GAMING):
#ifdef AUDIO_ENABLE
            PLAY_SONG (gaming);
#endif
#ifdef RGBLIGHT_ENABLE
            rgblight_set_effect_range(0, 9);
            rgblight_sethsv(HSV_RED);
            rgblight_set();
#endif
        return true; break;
        case TO(_QWERTY):
#ifdef AUDIO_ENABLE
            PLAY_SONG (qwerty);
#endif
#ifdef RGBLIGHT_ENABLE
            rgblight_set_effect_range(0, 9);
            rgblight_sethsv(HSV_WHITE);
            rgblight_set();
#endif
        return true; break;
        case ESC_F19:
            if (record->event.pressed) {
                user_key_timer = timer_read();
                register_code(KC_F19);
            } else {
                unregister_code(KC_F19);
                if (timer_elapsed(user_key_timer) < TAPPING_TERM) {
                    tap_code(KC_ESC);
                }
            }
            return false; break;
        case AP_GLOB:
            host_consumer_send(record->event.pressed ? AC_NEXT_KEYBOARD_LAYOUT_SELECT : 0);
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYMBL, _CNTRL, _MOUSE);
    state = update_tri_layer_state(state, _SHORTCUTS, _CNTRL, _ADJUST);
    return state;
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(_QWERTY)) {
        return true;
    }
    return false;
}
