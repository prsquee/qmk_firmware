/* Copyright 2015-2017 Jack Humbert
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

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _SQUEE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  SQUEE,
  EMOJI,
  CONSOLE,
  S1,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* {{{ QWERTY
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  BS  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | HYP  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;: |enter |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |shift.|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /? |shift'|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |Ctrl\ |  😃  | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_planck_grid(
      KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,            KC_O,    KC_P,    KC_BSPC,
      MEH_T(KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,            KC_L,    KC_SCLN, KC_ENT,
      LSFT_T(KC_COLN),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM,         KC_DOT,  KC_SLSH, RSFT_T(KC_QUOT),
      LCTL_T(KC_PIPE),  EMOJI,   KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,  RALT_T(KC_LEFT), KC_DOWN, KC_UP,   RGUI_T(KC_RGHT)
  ),
  /* }}} */
  /* {{{  Raise
   * ,-----------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   -_ |   =+ | BS   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   ~  | .    |      |      |      |      |      |   (  |   )  |   [{ |   ]} |  |   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      | mute | vol- | vol+ |  <<  | play |  >>  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT_planck_grid(
      KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC,     KC_AMPR,    KC_ASTR, KC_MINS, KC_EQL,  _______,
      KC_TILD, KC_INS,  _______, _______, _______, _______,  KC__MUTE,    KC_LPRN,    KC_RPRN, KC_LBRC, KC_RBRC, KC_PIPE,
      _______, _______, _______, _______, _______, KC__MUTE, KC__VOLDOWN, KC__VOLUP,  KC_MRWD, KC_MPLY, KC_MFFD, _______,
      _______, _______, _______, _______, _______, _______,  _______,     _______,    _______, _______, _______, _______
  ),
  /* }}} */
  /* {{{  Lower
   * ,-----------------------------------------------------------------------------------.
   * |   ~  |  0   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  BS  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Del  | home |  up  | end  | pgup |      |      |   *  |   4  |   5  |   6  |  +   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      | left | down | right| pgdn |      |      |   /  |   1  |   2  |   3  |  -   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |   0  |   .  |   =  | enter|
   * `-----------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_planck_grid(
      CONSOLE, KC_0,    KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7, KC_8,  KC_9,     _______,
      KC_DEL,  KC_HOME, KC_UP,    KC_END,   KC_PGUP, _______, _______, KC_PAST,  KC_4, KC_5,  KC_6,     KC_PPLS,
      _______, KC_LEFT, KC_DOWN,  KC_RIGHT, KC_PGDN, _______, _______, KC_PSLS,  KC_1, KC_2,  KC_3,     KC_PMNS,
      _______, _______, _______,  _______,  _______, _______, _______, _______,  KC_0, KC_DOT, KC_EQL,  KC_PENT
  ),
  /* }}} */
  /* {{{ SQUEE
   * ,-----------------------------------------------------------------------------------.
   * |      |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |   A  |   R  |   S  |   T  |   G  |   K  |   N  |   E  |   I  |   O  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |   Z  |   X  |   C  |   D  |   V  |   M  |   H  |   ,  |   .  |   /  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_SQUEE] = LAYOUT_planck_grid(
      KC_TAB,           KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,   KC_U,     KC_Y,   KC_SCLN,        KC_BSPC,
      MEH_T(KC_ESC),    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,   KC_E,     KC_I,   KC_O,           KC_ENT,
      LSFT_T(KC_COLN),  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_M,    KC_H,   KC_COMM,  KC_DOT, KC_SLSH,        RSFT_T(KC_QUOT),
      LCTL_T(KC_PIPE),  EMOJI,   KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,  RALT_T(KC_LEFT),  KC_DOWN, KC_UP, RGUI_T(KC_RGHT)
  ),
  /* }}} */
  /* {{{ Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * |  F1  | F2   |  F3  | F4   | F5   | F6   | F7   | F8   | F9   | F10  | F11  | F12  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | reset|debug |      |      |      |qwerty|squee |      |      |      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | clkon|clkoff|clk_up|clk_dn|      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_planck_grid(
    KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,   KC_F12,
    RESET,    DEBUG,  _______,  _______,  S1,       QWERTY,   SQUEE,   _______, _______,  _______,  _______,  _______,
    CK_ON,    CK_OFF,   CK_UP,  CK_DOWN,  CK_RST,   MU_ON,    MU_OFF,  _______, _______,  _______,  _______,  _______,
    _______,  _______,  _______, _______, _______,  _______,  _______, _______, _______,  _______,  _______,  _______
  )
  /* }}} */
};


#ifdef AUDIO_ENABLE
  float stillalive[][2] = SONG(STILL_ALIVE);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case SQUEE:
      if (record->event.pressed) {
        print("mode just switched to SQUEE LAYER\n");
        set_single_persistent_default_layer(_SQUEE);
      }
      return false;
      break;
    case EMOJI:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LGUI(SS_TAP(X_SPACE))));
      }
      return false;
      break;
    case CONSOLE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`"));
      }
      return false;
      break;
    case S1:
      if (record->event.pressed) {
        PLAY_SONG(stillalive);
      }
      return false;
      break;
  }
  return true;
}
