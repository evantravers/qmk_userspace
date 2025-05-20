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

#pragma once
#include QMK_KEYBOARD_H

#include "version.h"
#include "eeprom.h"
#include "wrappers.h"

#define SYMBL     LT(_SYMBL, KC_BSPC)
#define CNTRL     LT(_CNTRL, KC_SPC)
#define SHORTCUTS MO(_SHORTCUTS)
#define SPC_MUTE
#define ENT_SK    LT(_SHORTCUTS, KC_ENT)
#define TAB_SK    LT(_SHORTCUTS, KC_TAB)
#define TAB_GSK    LT(_GAMING2, KC_TAB)
#define QUOTE_SK  LT(_SHORTCUTS, KC_QUOT)
#define ZOOMIN    LGUI(KC_EQL)
#define ZOOMOUT   LGUI(KC_MINS)
#define TABN      LSFT(LGUI(KC_RBRC))
#define TABP      LSFT(LGUI(KC_LBRC))
#define HBCK      LGUI(KC_LBRC)
#define HFWD      LGUI(KC_RBRC)
#define WIN_MUTE  TD(TD_MUTE)
#define SCRNST    TD(TD_SCRNST)
#define PREV_NEXT TD(TD_PREV_NEXT)
#define TAB_ESC   TD(TD_TAB_ESC)
#define PASS      LGUI(KC_BSLS)
#define MUTE      LSFT(LGUI(KC_M))
#define DWN_MUTE  TD(TD_DWNMUTE)

#define ALT_ESC   LALT_T(KC_ESC)
#define ALT_ENT   RALT_T(KC_ENT)
#define GUI_BSPC  LGUI_T(KC_BSPC)
#define GUI_DEL   RGUI_T(KC_DEL)
#define LSHFT     LSFT_T(KC_TAB)
#define RSHFT     RSFT_T(KC_COLON)

enum userspace_tapdances {
  TD_PREV_NEXT,
  TD_SCRNST,
  TD_MUTE,
  TD_TAB_ESC,
  TD_DWNMUTE,
};

enum userspace_custom_keycodes {
  ESC_F19 = SAFE_RANGE,
  AP_GLOB // apple globe key
};

/* Define layer names */
enum userspace_layers {
  _QWERTY,
  _GAMING,
  _SYMBL,
  _CNTRL,
  _MOUSE,
  _SHORTCUTS,
  _NUDGE,
  _GAMING2,
  _ADJUST
};
