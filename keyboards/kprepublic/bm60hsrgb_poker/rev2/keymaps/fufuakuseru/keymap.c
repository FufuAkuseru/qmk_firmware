/* Copyright 2022 bdtc123 - kaen_ono
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

// clang-format off

#include QMK_KEYBOARD_H

enum kaen_ono_layers {
    _DEF,
    _FUN,
    _FUU
};

/*
    ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──────┐
    │ ⎋ │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │    ⌫ │
    ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
    │  ↹ │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \ │
    ├─────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤
    │     ⇪ │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │    ↵ │
    ├───────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──────┤
    │       ⇧ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │      ⇧ │
    ├───┬───┬─┴─┬─┴───┴───┴───┴───┴───┴───┴───┴┬──┴┬──┴┬───┬───┤
    │ ⎈ │ ❖ │ ⎇ │            SPACE             │ ⎇ │ f │ ❖ │ ⎈ │
    └───┴───┴───┴──────────────────────────────┴───┴───┴───┴───┘
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF] = LAYOUT_60_ansi(
        QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_6,   KC_7,   KC_8,      KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_Y,   KC_U,   KC_I,      KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_H,   KC_J,   KC_K,      KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_N,   KC_M,   KC_COMM,   KC_DOT, KC_SLSH, KC_RSFT,
        KC_PAUSE, KC_LGUI, KC_LALT,                   KC_SPC,                KC_RALT,   MO(1),  KC_RGUI, KC_RCTL
    ),
    [_FUN] = LAYOUT_60_ansi(
        KC_PGUP, KC_F1,   KC_F2,   KC_F3,     KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_PGDN, _______, KC_UP,   KC_MPLY,   KC_MNXT, KC_VOLU, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPRV, KC_VOLD, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______,
        MO(2),   KC_PSCR, KC_INS,  KC_HOME, KC_END,  _______, RGB_TOG,  _______, _______, UC(0x2026), UC(0x203D), _______,
        KC_LCTL, _______, _______,                  UC(0x00A0),                  _______, _______, _______,  _______
    ),
    [_FUU] = LAYOUT_60_ansi(
        QK_BOOT,   KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,   KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX,
        XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, KC_WH_U,  KC_NUM,  KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_PMNS, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_L, KC_WH_D, KC_WH_R,  KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_PPLS, XXXXXXX,
        XXXXXXX, KC_BTN3, KC_BTN4, KC_BTN5, XXXXXXX, KC_P0,   KC_P1,    KC_P2,   KC_P3,   KC_PDOT, XXXXXXX, XXXXXXX,
        XXXXXXX, UC_NEXT, UC_PREV,                   XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

// Shift + Backspace = Delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// Shift + L_CTRL = CapsLock
const key_override_t capslock_key_override = ko_make_basic(MOD_MASK_GUI, KC_LCTL, KC_CAPS);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]) {
    &delete_key_override,
    &capslock_key_override,
    NULL // Null terminate the array of overrides!
};
