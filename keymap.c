/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

// TODO remove clutter

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t quote_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_QUOT, DE_MINS);


const key_override_t *key_overrides[] = {
	&delete_key_override,
    &quote_key_override
};
enum custom_keycodes {
    CTLZ = SAFE_RANGE,
    CLSE,
    CALL,
    CTLB,
    SPLTH,
    SPLTV,
    MCOPY,
    MCUT,
    MPSTE,
    BCTK,
    CIRCUM,
    MYQUOT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CTLZ:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("z"));
        }
        break;

    case CLSE:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("w"));
        }
        break;

    case MCOPY:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("c"));
        }
        break;

    case MCUT:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("x"));
        }
        break;

    case MPSTE:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("v"));
        }
        break;

    case CALL:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("a"));
        }
        break;

    case CTLB:
    if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b"));
    }
    break;

    case SPLTH:
    if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b") SS_LSFT("2"));
    }
    break;

    case SPLTV:
    if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b") SS_LSFT("5"));
    }
    break;

    case BCTK:
        if (record->event.pressed) {
            SEND_STRING("`");
        }
        break;

    case CIRCUM:
        if (record->event.pressed) {
            SEND_STRING("^");
        }
        break;

    case MYQUOT:
        if (record->event.pressed) {
            SEND_STRING("'");
        }
        break;
    }
    return true;
};

#define CESC LCTL_T(KC_ESC)
#define TABB C(S(KC_TAB))
#define TABF C(KC_TAB)
#define CTLA C(KC_A)
#define COPY C(KC_INS)
#define PSTE S(KC_INS)
#define VUP KC_KB_VOLUME_UP
#define VDWN KC_KB_VOLUME_DOWN
#define ALFT A(KC_LEFT)
#define ARGT A(KC_RIGHT)
#define TMX C(KC_B)
#define PLAY KC_MEDIA_PLAY_PAUSE
#define MUTE KC_AUDIO_MUTE
#define NEXT KC_MEDIA_NEXT_TRACK
#define FAST KC_MEDIA_FAST_FORWARD
#define CCOM LCTL_T(KC_COMM)
#define SQUO SFT_T(KC_PIPE)
#define SCAPS SFT_T(KC_CAPS) //doesnt work
#define AALT LALT_T(DE_ADIA)
#define ALTE LALT_T(KC_ENT)
#define BSAL LALT_T(DE_BSLS)
#define RCAP SFT_T
#define SFTS SFT_T(DE_SS)


// will press enter, if alt was not used in combination
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALTE:
            return true;
        case LT(5,KC_TAB):
            return true;
        default:
            return false;
    }
}

// holds the key, when another key is pressed
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CESC:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

// TODO in Rev3 use alt as the extra button on the left side
// NORMAL
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       LT(5,KC_TAB),    DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                         DE_Z,    DE_U,    DE_I,    DE_O,    DE_P, DE_UDIA,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               CESC,    DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                         DE_H,    DE_J,    DE_K,    DE_L, DE_ODIA, DE_ADIA,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT,    DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,                         DE_N,    DE_M, DE_COMM,  DE_DOT, DE_MINS,    SFTS,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_LGUI,   TT(1),  KC_SPC,       ALTE,   MO(2), KC_BSPC
                                            //`--------------------------'  `--------------------------'

  ),

  // NUMBERS
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      DE_TILD, DE_ASTR,    KC_7,    KC_8,    KC_9, DE_MINS,                         BCTK, DE_DQUO, DE_QUOT, DE_AMPR, DE_PIPE,  DE_DLR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_EXLM, DE_SLSH,    KC_4,    KC_5,    KC_6,  DE_EQL,                        DE_AT, DE_LPRN, DE_RPRN, DE_LCBR, DE_RCBR, DE_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_0,  CIRCUM,    KC_1,    KC_2,    KC_3, DE_PLUS,                      DE_HASH, DE_LBRC, DE_RBRC, DE_LABK, DE_RABK, DE_PERC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           DE_DOT,   TG(1), DE_COMM,       ALTE,   MO(3), KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

  // VIM layout
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         CESC,    TABB,    TABF,    COPY,    PSTE,    CTLA,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, DE_DEG,   SPLTV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    VDWN,     VUP,    ALFT,    ARGT,     TMX,                     DE_SECT,    PLAY,     MUTE, DE_EURO, KC_HOME, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3), KC_LALT,       ALTE, _______, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

  //hier koennen maus und media keys hin... SOLLTEN SOGAR
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       QK_BOOT,  DF(4), XXXXXXX, XXXXXXX, XXXXXXX,   DF(6),                      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_PGDN, KC_PGUP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ACL0, KC_ACL2,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,             XXXXXXX, KC_BTN1, KC_BTN2,KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP,KC_KB_MUTE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,       ALTE, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  //hier kommt die gaming variante hin
  [4] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_TAB,     DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                         DE_Z,    DE_U,    DE_I,    DE_O,    DE_P, DE_UDIA,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LCTL,    DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                         DE_H,    DE_J,    DE_K,    DE_L, DE_ODIA,    AALT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT,    DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,                         DE_N,    DE_M, DE_COMM,  DE_DOT,   DE_SS,  KC_ESC,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                DE_J,   DE_K,  KC_SPC,         KC_ENT,   DF(0), KC_BSPC
                                            //`--------------------------'  `--------------------------'
  ),

  // ONEHAND layout
  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_LALT,  KC_TAB, KC_LSFT,   KC_F5,   KC_F6,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         CESC,    TABB,    TABF,    COPY,    PSTE,    CTLA,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_HOME,    VDWN,     VUP,    ALFT,    ARGT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, XXXXXXX,  KC_SPC,     KC_ENT, XXXXXXX, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

  // default blender
  // CAREFULL T IS Z
  [6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    DE_Q,    DE_W,    DE_E,    DE_R,    DE_Z,                         DE_Z,    DE_U,    DE_I,    DE_O,    DE_P, DE_UDIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         CESC,    DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                         DE_H,    DE_J,    DE_K,    DE_L, DE_ODIA, DE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,                         DE_N,    DE_M, DE_COMM,  DE_DOT, DE_MINS,    SFTS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          TT(8),   TT(7),      ALTE,       ALTE,     DF(0), KC_BSPC
                                      //`--------------------------'  `--------------------------'

  ),

  // probably the most common F keys
  // NUMBERS Blender
  // need M, L(link)
  [7] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      DE_TILD,    DE_P,    KC_7,    KC_8,    KC_9,    DE_K,                         BCTK, DE_DQUO, DE_QUOT, DE_AMPR, DE_PIPE,  DE_DLR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_HOME,    DE_L,    KC_4,    KC_5,    KC_6,    DE_I,                        DE_AT, DE_LPRN, DE_RPRN, DE_LCBR, DE_RCBR, DE_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_0,    DE_M,    KC_1,    KC_2,    KC_3,    DE_O,                      DE_HASH, DE_LBRC, DE_RBRC, DE_LABK, DE_RABK, DE_PERC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           DE_DOT,   TG(7), DE_COMM,       ALTE, XXXXXXX, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

  // NUMPAD Blender
  [8] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_PSLS,   KC_P7,   KC_P8,   KC_P9, KC_PPLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         CESC, KC_PAST,   KC_P4,   KC_P5,   KC_P6, KC_PMNS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_P0,   KC_P1,   KC_P2,   KC_P3, KC_PDOT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            TG(8), KC_PENT,  KC_SPC,     KC_ENT, XXXXXXX, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),



};





#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}


#endif // OLED_ENABLE
