/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
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

#include QMK_KEYBOARD_H

#ifdef OS_DETECTION_ENABLE
  #include "os_detection.h"
#endif

enum os_variant_t {
   OS_UNSURE,
   OS_LINUX,
   OS_WINDOWS,
   OS_MACOS,
   OS_IOS,
} os_variant_t;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_number {
   _QWERTY = 0,
   _RAISE,
   _LOWER,
   IMEON,
   IMEOFF
};

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MOU 3
#define KC_LOMH LT(_LOWER, INEOFF)
#define KC_RAHE LT(_RAISE, IMEON)
#define KC_SFEN SFT_T(KC_ENT)
#define KC_SFSP SFT_T(KC_SPC)
#define KC_CTGU LCTL_T(KC_LGUI)
#define KC_LOCS OSM(MOD_LSFT)
#define ALT_TAB LALT(KC_TAB)
#define MOV_MOU LO(_MOU)
#define RET_DEF LO(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
   //,-----------------------------------------------------.                    ----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_COLN,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LGUI,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              KC_LCTL,  KC_LOMH, KC_SFSP, RET_DEF,     MOV_MOU, KC_SFEN, KC_RAHE, KC_RCTL
    //                     `----------+--------+---------+--------'   `--------+---------+--------+---------'
    ),

    [_RAISE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB, KC_EXLM,  KC_AT,  KC_HASH,  KC_DLR, KC_PERC,                      KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_CIRC, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC,  KC_DQT, C(KC_S), KC_LABK, KC_RABK, KC_QUOT,                      KC_MINS,  KC_EQL, KC_LPRN, KC_RPRN, KC_PIPE,  KC_GRV,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                               KC_LCTL, KC_LOMH, KC_SFSP,  RET_DEF,     MOV_MOU, KC_SFEN, KC_RAHE, KC_RCTL
    //                      `----------+--------+---------+--------'   `--------+---------+--------+---------'
    ),

    [_LOWER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,   KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                        XXXXXXX, KC_PGUP,  KC_UP,  XXXXXXX, XXXXXXX, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC,   KC_6,    KC_7,    KC_8,    KC_9,   KC_0,                        KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,  KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                               KC_LCTL, KC_LOMH, KC_SFSP, RET_DEF,     MOV_MOU, KC_SFEN, KC_RAHE, KC_RCTL
    //                        `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),

   [_MOU] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, KC_WH_U,                      KC_WH_U, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BTN2, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,                      KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_BTN2,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_ACL2, KC_ACL1, KC_ACL0, KC_WH_D,                      KC_WH_D, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                KC_LCTL, XXXXXXX, KC_BTN1, RET_DEF,    MOV_MOU, KC_BTN1, XXXXXXX, KC_RCTL
    //                        `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   // uint16_t henk = KC_INT4;
   // uint16_t mhen = KC_INT5;

   // #ifdef OS_DETECTION_ENABLE
      // switch (detected_host_os()) {
      //    case OS_UNSURE:
      //       break;
      //    case OS_LINUX:
      //       break;
      //    case OS_WINDOWS:
      //          break;
      //    case OS_MACOS:
      //          break;
      //    case OS_IOS:
      //          break;
      // }
   // #endif
   switch (keycode) {
      case IMEON:
        if (record->event.pressed) {
          register_code(KC_INT4);
          register_code(KC_LNG1);
        } else {
          unregister_code(KC_INT4);
          unregister_code(KC_LNG1);
        }
        return false;
      case IMEOFF:
        if (record->event.pressed) {
          register_code(KC_INT5);
          register_code(KC_LNG2);
        } else {
          unregister_code(KC_INT5);
          unregister_code(KC_LNG2);
        }
        return false;
      default:
        return true;
   }
}
