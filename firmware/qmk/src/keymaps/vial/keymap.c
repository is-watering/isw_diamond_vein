/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
#include "wpm.h"


enum layer_names {
    _LAYER_0,
    _LAYER_1,
    _LAYER_2,
    _LAYER_3,
    _LAYER_4,
    _LAYER_5,
    _LAYER_6
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Game_1 */
	[_LAYER_0] = LAYOUT(
		  KC_ESC,         RGB_TOG,
		KC_LSFT,  KC_W,
		  KC_A,    KC_D,            KC_BTN2,
		MO(1), KC_S,         KC_E,
		  XXXXXXX,        KC_BTN2,  KC_BTN1,
		KC_LCTL,        KC_Z,  KC_SPC
	),

/* Game_1_lower */
	[_LAYER_1] = LAYOUT(
		    KC_1,         RGB_TOG,
		XXXXXXX,  KC_2,
		    XXXXXXX, KC_3,          KC_Q,
		XXXXXXX,  XXXXXXX,     XXXXXXX,
		    XXXXXXX,      XXXXXXX,  KC_B,
		XXXXXXX,      XXXXXXX, KC_F5
	),

/* Game_2 */
	[_LAYER_2] = LAYOUT(
		    KC_ESC,       RGB_TOG,
		KC_1,  KC_2,
		    XXXXXXX, KC_3,          KC_I,
		MO(3), XXXXXXX,        KC_E,
		    KC_LSFT,      KC_BTN2,  KC_BTN1,
		KC_SPC,         KC_M,  KC_TAB
	),

/* Game_2_lower */
	[_LAYER_3] = LAYOUT(
		    KC_R,         RGB_TOG,
		KC_N,  KC_Q,
        XXXXXXX, KC_W,          KC_F1,
		XXXXXXX, XXXXXXX,      KC_F2,
	      XXXXXXX,      KC_V,     KC_T,
		XXXXXXX,      XXXXXXX, XXXXXXX
	),

/* Numpad */
	[_LAYER_4] = LAYOUT(
		    KC_PPLS,      RGB_TOG,
		KC_PMNS, KC_P9,
        KC_P8, KC_P6,           KC_PENT,
		KC_P7,  KC_P5,         KC_P3,
	      KC_P4,         KC_P2,   KC_PDOT,
		MO(5),          KC_P1, KC_P0
	),

/* Numpad_lower */
	[_LAYER_5] = LAYOUT(
		    KC_PAST,      RGB_TOG,
		KC_PSLS, KC_PGUP,
        KC_UP, KC_RIGHT,        KC_BSPC,
		KC_HOME, KC_PEQL,      KC_PGDN,
	      KC_LEFT,      KC_DOWN,  KC_DELETE,
		XXXXXXX,       LSFT(KC_END), KC_TAB
	),

/* Config */
	[_LAYER_6] = LAYOUT(
		    RGB_TOG,      RGB_TOG,
		RGB_VAI, RGB_VAD,
        RGB_HUI, RGB_HUD,       XXXXXXX,
		RGB_SAI, RGB_SAD,        XXXXXXX,
	      RGB_MOD,        XXXXXXX,  XXXXXXX,
		RGB_RMOD,        QK_BOOT, XXXXXXX
	),

};


/* `ENCODER_MAP_ENABLE = yes` must be added to the rules.mk at the KEYMAP level. See QMK docs. */
/* Remove the following code if you do not enable it in your keymap (e.g. default keymap). */
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
	[0] = { ENCODER_CCW_CW(TO(2), TO(6)) },
	[1] = { ENCODER_CCW_CW(TO(2), TO(0)) },
	[2] = { ENCODER_CCW_CW(TO(4), TO(0)) },
	[3] = { ENCODER_CCW_CW(TO(4), TO(2)) },
	[4] = { ENCODER_CCW_CW(TO(6), TO(2)) },
	[5] = { ENCODER_CCW_CW(TO(6), TO(4)) },
	[6] = { ENCODER_CCW_CW(TO(0), TO(4)) }
};
#endif


#ifdef OLED_ENABLE

void oled_write_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _LAYER_0:
            oled_write_ln_P(PSTR("Game_1"), false);
            break;
        case _LAYER_1:
            oled_write_ln_P(PSTR("Game_1_lower"), false);
            break;
        case _LAYER_2:
            oled_write_ln_P(PSTR("Game_2"), false);
            break;
        case _LAYER_3:
            oled_write_ln_P(PSTR("Game_2_lower"), false);
            break;
        case _LAYER_4:
            oled_write_ln_P(PSTR("Numpad"), false);
            break;
        case _LAYER_5:
            oled_write_ln_P(PSTR("Numpad_lower"), false);
            break;
        case _LAYER_6:
            oled_write_ln_P(PSTR("Config"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
            break;
    };
    oled_write_ln_P(PSTR(" "), false);
}

void oled_write_wpm(void) {
    static char wpm[5];
    oled_write_P(PSTR("WPM: "), false);
    itoa(get_current_wpm(), wpm, 10);
    oled_write_ln(wpm, false);
}

bool oled_task_user(void) {
    oled_write_layer_state();
    oled_write_wpm();
    return false;
}

#endif // OLED_ENABLE