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

#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_keycodes {
    COMM = SAFE_RANGE,
	SELECT,
	FROM,
	JOIN,
	WHERE,
	GROUP,
	HAVING,
	LIMIT,
	ORDER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LCTL_T(KC_BSLS),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                  KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       GUI_T(KC_DEL), MO(1), KC_SPC,     SFT_T(KC_ENT),   MO(2), KC_LALT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_10, KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_F12, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL_T(KC_BSLS), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              KC_PPLS, KC_PMNS, KC_PAST, KC_DOT, KC_PSLS, KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_DEL, _______, KC_SPC,    KC_ENT,   MO(3), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_LPRN, KC_ASTR, KC_RPRN,    KC_P, KC_PIPE,                      KC_PSCR, LCTL(LSFT(KC_TAB)),LCTL(KC_W),LCTL(KC_TAB), XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LBRC,    COMM, KC_MINUS,KC_COMMA,  KC_DOT, KC_RBRC,                      KC_HOME, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,  KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LCTL(KC_BSLS), KC_QUOT,XXXXXXX, KC_EQL, LCTL(KC_DOT), KC_TILD,                    KC_PGUP, KC_PGDN, KC_COMM,  KC_DOT, MO(4), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_DEL,   MO(3),  KC_SPC,   KC_ENT, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______,  KC_SPC,     KC_ENT, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
	  
	    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, WHERE,     FROM, XXXXXXX, GROUP,                      JOIN,  LIMIT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, SELECT, XXXXXXX, XXXXXXX,                      HAVING, XXXXXXX, XXXXXXX, XXXXXXX, ORDER, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
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

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

//void oled_render_logo(void) {
 //  static const char PROGMEM crkbd_logo[] = {
//    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
//      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
 //     0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
//      0};

//   oled_write_P(crkbd_logo, false);

//}

//void oled_task_user(void) {
//    if (is_keyboard_master()) {
//        oled_render_layer_state();
//        oled_render_keylog();
//    } else {
//        oled_render_logo();
//    }
//}


static void render_logo(void) {
  static const char PROGMEM my_logo[] = {
    // Paste the code from the previous step below this line!
// 'canvas_logo', 128x32px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0x80, 0x80, 0x80, 
0x80, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 
0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x80, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x80, 0x80, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x80, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x80, 0x80, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xc1, 0xf1, 0x19, 0x04, 0x01, 0x01, 0xff, 0xff, 0x01, 
0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0xf8, 0xf8, 0x04, 0x00, 0xfe, 0xff, 0x00, 0xdf, 0x01, 
0x01, 0x01, 0x03, 0x07, 0x1f, 0xfe, 0xf8, 0x00, 0x00, 0x00, 0x80, 0x80, 0xf0, 0xfc, 0xde, 0x00, 
0x41, 0x40, 0x40, 0xff, 0xff, 0xff, 0x40, 0xe1, 0x00, 0x00, 0x83, 0xff, 0xff, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x40, 0xf8, 0xfe, 0x00, 0x00, 0xff, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x40, 0xf0, 0xfe, 0x01, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x20, 0x20, 0x60, 0xfe, 0xe3, 0x00, 0x7e, 0xff, 0xe0, 0x00, 0x00, 0xe0, 0xf8, 0x06, 
0x00, 0xfc, 0xfe, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x1f, 0x3c, 0x78, 0x74, 0x63, 0x60, 0x60, 
0x60, 0x60, 0x20, 0x10, 0x08, 0x00, 0x00, 0x0f, 0x1f, 0x3c, 0x7c, 0x73, 0x61, 0x60, 0x77, 0x20, 
0x20, 0x10, 0x18, 0x0c, 0x07, 0x03, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc1, 0xd3, 0xc5, 0x00, 
0x00, 0x00, 0x00, 0x3f, 0x7f, 0x7f, 0x20, 0x10, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x20, 0x00, 0x00, 
0x00, 0x00, 0x40, 0x22, 0x3f, 0x33, 0x38, 0x36, 0x33, 0x30, 0x70, 0x70, 0x60, 0x20, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x3f, 0x27, 0x30, 0x34, 0x33, 0x30, 0x30, 0x70, 0x60, 0x20, 0x00, 0x00, 
0x20, 0x20, 0x30, 0x30, 0x70, 0x4f, 0x47, 0x40, 0x40, 0x3f, 0x0f, 0x00, 0x00, 0x07, 0x0f, 0x1e, 
0x3c, 0x73, 0x70, 0x60, 0x60, 0x60, 0x60, 0x20, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  oled_write_raw_P(my_logo, sizeof(my_logo));
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to put your image on the master side, put your function call here:
           oled_render_layer_state();
        oled_render_keylog();
  } else {
    // And if you want to put your image on the slave side, put it here instead:
    render_logo();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
	

   switch (keycode) {
    case COMM:
        if (record->event.pressed) {
            // when keycode COMM is pressed
            SEND_STRING("--");
        } else {
            // when keycode COMM is released
        }
        break;
		   
		       case SELECT:
        if (record->event.pressed) {
            // when keycode SELECT is pressed
            SEND_STRING("DKUKCF * ");
        } else {
            // when keycode SELECT is released
        }
        break;
		   
		       case JOIN:
        if (record->event.pressed) {
            // when keycode JOIN is pressed
            SEND_STRING("Y:LJ ");
        } else {
            // when keycode JOIN is released
        }
        break;
		   
		       case FROM:
        if (record->event.pressed) {
            // when keycode FROM is pressed
            SEND_STRING("ES:M ");
        } else {
            // when keycode FROM is released
        }
        break;
		   
		       case WHERE:
        if (record->event.pressed) {
            // when keycode WHERE is pressed
            SEND_STRING("WHKSK 1=1 \n AJG ");
        } else {
            // when keycode WHERE is released
        }
        break;
		   
		       case GROUP:
        if (record->event.pressed) {
            // when keycode GROUP is pressed
            SEND_STRING("TS:IR BO ");
        } else {
            // when keycode GROUP is released
        }
        break;
		   
		       case HAVING:
        if (record->event.pressed) {
            // when keycode HAVUKD is pressed
            SEND_STRING("HAVLJT ");
        } else {
            // when keycode HAVING is released
        }
        break;
		       case LIMIT:
        if (record->event.pressed) {
            // when keycode LIMIT is pressed
            SEND_STRING("ULMLF 1000p");
        } else {
            // when keycode LIMIT is released
        }
        break;
		          case ORDER:
        if (record->event.pressed) {
            // when keycode ORDER is pressed
            SEND_STRING(":SGKS BO ");
        } else {
            // when keycode ORDER is released
        }
        break;
    }
	
  return true;
};
#endif // OLED_ENABLE
