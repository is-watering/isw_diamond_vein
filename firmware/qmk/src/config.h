/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x3B, 0x4B, 0x2A, 0x07, 0xB7, 0x95, 0xBA, 0x7D}

/* CONSIDER ADDING AN UNLOCK COMBO. SEE DOCUMENTATION. */
#define VIAL_INSECURE

/* i2c */
#define HAL_USE_I2C TRUE
#define I2C1_SCL_PIN GP3
#define I2C1_SDA_PIN GP2

/* define OLED Scroll and timeout */
#ifdef OLED_ENABLE
#define OLED_TIMEOUT 180000 
#endif

/* layer */
#define DYNAMIC_KEYMAP_LAYER_COUNT 7