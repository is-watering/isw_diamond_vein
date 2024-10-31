/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
		KC_ESC,
		KC_LSFT, KC_W,
		KC_Q,
		KC_A,    KC_D,
		KC_1,    KC_S,    KC_E,
		KC_2,    KC_3,    KC_4,
		KC_LCTL, KC_5,    KC_SPC
	),

	[1] = LAYOUT(
		XXXXXXX,
		XXXXXXX, XXXXXXX,
		XXXXXXX,
		XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX
	),

	[2] = LAYOUT(
		XXXXXXX,
		XXXXXXX, XXXXXXX,
		XXXXXXX,
		XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX
	),

	[3] = LAYOUT(
		XXXXXXX,
		XXXXXXX, XXXXXXX,
		XXXXXXX,
		XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX
	),

};


/* `ENCODER_MAP_ENABLE = yes` must be added to the rules.mk at the KEYMAP level. See QMK docs. */
/* Remove the following code if you do not enable it in your keymap (e.g. default keymap). */
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
	[0] = { ENCODER_CCW_CW(KC_NO, KC_NO) }
	[1] = { ENCODER_CCW_CW(KC_NO, KC_NO) }
	[2] = { ENCODER_CCW_CW(KC_NO, KC_NO) }
	[3] = { ENCODER_CCW_CW(KC_NO, KC_NO) }
};
#endif
