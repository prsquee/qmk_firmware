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
  ALFRED,
  EMOJI,
  S1,
  S2,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  BS  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | HYP  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;: |  '"  |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | S/Dot|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /? |s/Entr|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl |  😃  | Alt  | GUI  |Lower |    Space   |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_planck_grid(
      KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,            KC_O,    KC_P,    KC_BSPC,
      MEH_T(KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,            KC_L,    KC_SCLN, KC_QUOT,
      LSFT_T(KC_DOT),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM,         KC_DOT,  KC_SLSH, KC_SFTENT,
      LCTL_T(KC_PIPE),  EMOJI,   KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   RALT_T(KC_LEFT), KC_DOWN, KC_UP,   RGUI_T(KC_RGHT)
  ),

  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   -_ |   =+ | BS   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |  ~   |insert| home | pgup |      |      |      |   (  |   )  |   [{ |   ]} |  |   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      | delet| end  | pgdn |      |      |      |      |      |      |      |enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      | mute | Vol- | Vol+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT_planck_grid(
      KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,   KC_MINS,     KC_EQL,    _______,
      KC_TILD, KC_INS,  KC_HOME, KC_PGUP, _______, _______, _______, KC_LPRN, KC_RPRN,   KC_LBRC,     KC_RBRC,   KC_PIPE,
      _______, KC_DEL,  KC_END,  KC_PGDN, _______, _______, _______, _______, _______,   _______,     _______,   _______,
      _______, _______, _______, _______, _______, _______, _______, _______, KC__MUTE,  KC__VOLDOWN, KC__VOLUP, KC_MPLY
  ),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |   ~  |  0   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  BS  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Del  | home |  up  | end  |  S1  |      |      |   *  |   4  |   5  |   6  |  +   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      | left | down | right|  S2  |      |      |   /  |   1  |   2  |   3  |  -   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |   ALFRED    |      |   0  |   .  |   =  | enter|
   * `-----------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_planck_grid(
      KC_TILD, KC_0,    KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7, KC_8,  KC_9,     _______,
      KC_DEL,  KC_HOME, KC_UP,    KC_END,   S1,      _______, _______, KC_PAST,  KC_4, KC_5,  KC_6,     KC_PPLS,
      _______, KC_LEFT, KC_DOWN,  KC_RIGHT, S2,      _______, _______, KC_PSLS,  KC_1, KC_2,  KC_3,     KC_PMNS,
      _______, _______, _______,  _______,  _______, ALFRED,  _______, _______,  KC_0, KC_DOT, KC_EQL,  KC_PENT
  ),
  /* SQUEE
   * ,-----------------------------------------------------------------------------------.
   * |  +   |   7  |   8  |   9  |  =   |      |      |      |      |   (  |   )  | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |  -   |   4  |   5  |   6  |      |      |      |      |      |   [  |   ]  |  |   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |  *   |   1  |   2  |   3  |      |      |      |      |      |   {  |   }  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |  /   |   0  |  .   | enter|      |             |      | mute | prev | next | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_SQUEE] = LAYOUT_planck_grid(
      KC_PPLS, KC_P7, KC_P8,  KC_P9,   KC_EQL,  _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_BSPC,
      KC_PMNS, KC_P4, KC_P5,  KC_P6,   _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_QUOT,
      KC_PAST, KC_P1, KC_P2,  KC_P3,   _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_ENT ,
      KC_PSLS, KC_P0, KC_DOT, KC_PENT, LOWER,   KC_SPC,  KC_SPC,  RAISE,  KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* Adjust (Lower + Raise)
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
    RESET,    DEBUG,  _______,  _______, _______, QWERTY,   SQUEE,   _______, _______,  _______,  _______,  _______,
    CK_ON,    CK_OFF,   CK_UP,  CK_DOWN,  CK_RST,   MU_ON,    MU_OFF,  _______, _______,  _______,  _______,  _______,
    _______,  _______,  _______, _______, _______,  _______,  _______, _______, _______,  _______,  _______,  _______
  )
};


#ifdef AUDIO_ENABLE
  float test1[][2] = SONG(      H__NOTE(_G5),  \
                                H__NOTE(_FS5), \
                                H__NOTE(_E5),  \
                                H__NOTE(_E5),  \
                                W__NOTE(_FS5)  );

  float test2[][2] = SONG (
                                H__NOTE(_A4), \
                                H__NOTE(_AS4), \
                                W__NOTE(_C5), \
                                W__NOTE(_F5), \
                                H__NOTE(_E5), \
                                H__NOTE(_D5), \
                                H__NOTE(_D5), \
                                H__NOTE(_C5), \
                                H__NOTE(_D5), \
                                H__NOTE(_C5), \
                                W__NOTE(_C5), \
                                W__NOTE(_C5), \
                                H__NOTE(_A4), \
                                H__NOTE(_AS4), \
                                W__NOTE(_C5), \
                                W__NOTE(_F5), \
                                H__NOTE(_G5), \
                                H__NOTE(_F5), \
                                H__NOTE(_E5), \
                                H__NOTE(_D5), \
                                H__NOTE(_D5), \
                                H__NOTE(_E5), \
                                W__NOTE(_F5), \
                                W__NOTE(_F5), \
                                H__NOTE(_G5), \
                                H__NOTE(_A5), \
                                H__NOTE(_AS5), \
                                H__NOTE(_AS5), \
                                W__NOTE(_A5), \
                                W__NOTE(_G5), \
                                H__NOTE(_F5), \
                                H__NOTE(_G5), \
                                H__NOTE(_A5), \
                                H__NOTE(_A5), \
                                W__NOTE(_G5), \
                                W__NOTE(_F5), \
                                H__NOTE(_D5), \
                                H__NOTE(_C5), \
                                H__NOTE(_D5), \
                                H__NOTE(_F5), \
                                H__NOTE(_F5), \
                                W__NOTE(_E5), \
                                H__NOTE(_E5), \
                                H__NOTE(_FS5), \
                                H__NOTE(_FS5) );
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
    case ALFRED:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
      }
      return false;
      break;
    case EMOJI:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LGUI(SS_TAP(X_SPACE))));
      }
      return false;
      break;
    case S1:
      if (record->event.pressed) {
        PLAY_SONG(test1);
      }
      return false;
      break;
    case S2:
      if (record->event.pressed) {
        PLAY_SONG(test2);
      }
      return false;
      break;
  }
  return true;
}
