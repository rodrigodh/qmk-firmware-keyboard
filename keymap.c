// Copyright 2023-2025 Your Name
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Define layer names for better readability
enum layers {
  _BASE,
  _LOWER,
  _RAISE
};

// Define custom keycodes for Mod-Tap layer switching
// LT(layer, keycode) = Tap for keycode, Hold for layer
#define SPC_LOW LT(_LOWER, KC_SPC)
#define BSPC_RS LT(_RAISE, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer: QWERTY (i3 Optimized)
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | DEL  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | \|   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | LCTL |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  | SCLN | QUOT |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | LSFT |   Z  |   X  |   C  |   V  |   B  |                    |   N  |   M  | COMM | DOT  | SLSH | RSFT |
     * `-----------------------------------------'                    `-----------------------------------------'
     * | LGUI | LALT | SPC_LOW |                 | BSPC_RS| ENT  | NO   |
     * `-----------------------'                 `----------------------'
     */
    [_BASE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                   KC_LGUI, KC_LALT, SPC_LOW,         BSPC_RS, KC_ENT,  KC_NO
    ),

    /* LOWER Layer: Symbols and Navigation (Hold Space to access)
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `~  |  !   |  @   |  #   |  $   |  %   |                    |  ^   |  &   |  * |  (   |  )   |  _   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TRNS |  {   |  }   |  [   |  ]   |  |   |                    | PGUP | PGDN | HOME | END  | DEL  | TRNS |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TRNS |  <   |  >   |  (   |  )   | TRNS |                    | LEFT | DOWN |  UP  | RGHT |  [   |  ]   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |                    | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |
     * `-----------------------------------------'                    `-----------------------------------------'
     * | TRNS | TRNS | TRNS |                    | TRNS | TRNS | TRNS |
     * `--------------------'                    `--------------------'
     */
    [_LOWER] = LAYOUT(
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
        KC_TRNS, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PIPE,                   KC_PGUP, KC_PGDN, KC_HOME, KC_END,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_TRNS,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LBRC, KC_RBRC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /* RAISE Layer: Numbers, F-Keys and Media (Hold Backspace to access)
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | TRNS |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |                    |  =   |   7  |   8  |   9  |  -   | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |                    |  +   |   4  |   5  |   6  |  * |  /   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |                    | TRNS |   1  |   2  |   3  |  .   |  0   |
     * `-----------------------------------------'                    `-----------------------------------------'
     * | TRNS | TRNS | TRNS |                    | TRNS | TRNS | TRNS |
     * `--------------------'                    `--------------------'
     */
    [_RAISE] = LAYOUT(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_EQL,  KC_7,    KC_8,    KC_9,    KC_MINS, KC_F12,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_PLUS, KC_4,    KC_5,    KC_6,    KC_ASTR, KC_SLSH,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_1,    KC_2,    KC_3,    KC_DOT,  KC_0,
                                   KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS
    )
};
