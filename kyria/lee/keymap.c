/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _QWERTY = 0,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST
};

// Aliases for readability
#define QWERTY   DF(_QWERTY)

#define NAV      MO(_NAV)
#define SYM      MO(_SYM)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)
#define SPACE1  LT(_SYM, KC_SPC)
#define CTLGR LGUI(LCTL(KC_RIGHT))
#define CTLGL LGUI(LCTL(KC_LEFT))
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base Layer: QWERTY */
    [_QWERTY] = LAYOUT(
//  |--------+-------+-------+-------+-------+-------|                               |--------+-------+-------+-------+-------+-------| 
     KC_TAB  , KC_Q  ,  KC_W , KC_E  ,  KC_R , KC_T  ,                                KC_Y    , KC_U  , KC_I  , KC_O  ,  KC_P , KC_BSPC,
//  |--------+-------+-------+-------+-------+-------|                               |--------+-------+-------+-------+-------+-------| 
     CTL_ESC , KC_A  ,  KC_S , KC_D  ,  KC_F , KC_G  ,                                KC_H    , KC_J  , KC_K  , KC_L  ,KC_SCLN, KC_QUOT,
//  |--------+-------+-------+-------+-------+-------|                               |--------+-------+-------+-------+-------+-------| 
     SC_LSPO , KC_Z  ,  KC_X , KC_C  ,  KC_V , KC_B  ,SYM    ,ADJUST ,ADJUST ,  SYM  ,KC_N    , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH, SC_RSPC,
//  |--------+-------+-------+-------+-------+-------|-------,-------,-------,-------|--------+-------+-------+-------+-------+-------| 
                              KC_MUTE,KC_LGUI, NAV   ,SPACE1 , KC_ENT,KC_ENT ,KC_SPC , FKEYS , KC_RALT, KC_APP
//                           +-------+-------+-------|-------,-------,-------,-------|--------+-------+-------+
    ),

/* Sym Layer: Numbers and symbols */
    [_SYM] = LAYOUT(
//  |--------+-------+-------+-------+-------+-------|                               |--------+-------+-------+-------+-------+-------| 
     KC_GRV  , KC_1 ,  KC_2 ,  KC_3  , KC_4 ,   KC_5 ,                                KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,  KC_0 ,KC_PLUS,
//  |--------+-------+-------+-------+-------+-------|                               |--------+-------+-------+-------+-------+-------| 
     KC_TILD ,KC_EXLM, KC_AT ,KC_HASH, KC_DLR,KC_PERC,                                KC_CIRC, KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_EQL,
//  |--------+-------+-------+-------+-------+-------|                               |--------+-------+-------+-------+-------+-------| 
     KC_PIPE ,KC_BSLS, KC_EQL,KC_PLUS,KC_LCBR,KC_LBRC,_______,_______,_______,_______,KC_RBRC, KC_RCBR,KC_MINS,KC_UNDS,KC_MINS,KC_UNDS,
//  |--------+-------+-------+-------+-------+-------|-------,-------,-------,-------|--------+-------+-------+-------+-------+-------| 
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//                           +-------+-------+-------|-------,-------,-------,-------|--------+-------+-------+
    ),
/* Nav Layer: Media, navigation */
    [_NAV] = LAYOUT(
//  |--------+-------+-------+-------+-------+-------|                               |--------+-------+-------+-------+-------+-------| 
     QK_BOOT ,DB_TOGG,EE_CLR ,KC_MS_U,KC_NO  ,KC_WH_U,                                KC_PGUP ,KC_HOME, KC_UP , KC_END,KC_VOLU, KC_DEL,
//  |--------+-------+-------+-------+-------+-------|                               |--------+-------+-------+-------+-------+-------| 
     CTL_ESC ,KC_LGUI,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D,                                KC_PGDN ,KC_LEFT,KC_DOWN,KC_RGHT,KC_VOLD, KC_INS,
//  |--------+-------+-------+-------+-------+-------|                               |--------+-------+-------+-------+-------+-------| 
     _______ ,_______,CTLGL  ,_______,CTLGR  ,KC_NO  ,_______,_______,_______,_______,CTLGL   ,KC_BTN1,KC_BTN2,CTLGR  ,KC_MUTE, KC_PSCR,
//  |--------+-------+-------+-------+-------+-------|-------,-------,-------,-------|--------+-------+-------+-------+-------+-------| 
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


/* Function Layer: Function keys */
    [_FUNCTION] = LAYOUT(
//  |--------+-------+-------+-------+-------+-------|                               |--------+-------+-------+-------+-------+-------| 
      QK_BOOT,KC_F9 , KC_F10, KC_F11, KC_F12,KC_PSCR,                                 KC_PAUSE,_______,EE_CLR ,QK_BOOT,DB_TOGG,QK_BOOT,
//  |--------+-------+-------+-------+-------+-------|                               |--------+-------+-------+-------+-------+-------| 
      _______, KC_F5 , KC_F6 , KC_F7 , KC_F8 ,KC_CAPS,                                KC_PSCR,KC_RSFT,KC_RCTL,KC_RALT,KC_RGUI,_______,
//  |--------+-------+-------+-------+-------+-------|                               |--------+-------+-------+-------+-------+-------| 
      _______, KC_F1 , KC_F2 , KC_F3 , KC_F4 ,KC_SCRL,_______,_______,_______,_______, KC_NUM , CTLGL , KC_NO , CTLGR , KC_NO ,_______, 
//  |--------+-------+-------+-------+-------+-------|-------,-------,-------,-------|--------+-------+-------+-------+-------+-------| 
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/* Adjust Layer: Default layer settings, RGB */
    [_ADJUST] = LAYOUT(
//  |--------+-------+-------+-------+-------+-------|                               |--------+-------+-------+-------+-------+-------| 
     QK_BOOT ,DB_TOGG,EE_CLR,QWERTY ,_______, QK_RBT,                                 QK_RBT ,_______,_______,EE_CLR  ,DB_TOGG,QK_BOOT,
//  |--------+-------+-------+-------+-------+-------|                               |--------+-------+-------+-------+-------+-------| 
     _______ ,_______,_______,_______,_______,_______,                                 RGB_TOG,RGB_SAI,RGB_HUI,RGB_VAI,RGB_MOD,XXXXXXX,
//  |--------+-------+-------+-------+-------+-------|                               |--------+-------+-------+-------+-------+-------| 
     _______ ,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RGB_SAD,RGB_HUD,RGB_VAD,RGB_RMOD,XXXXXXX,
//  |--------+-------+-------+-------+-------+-------|-------+-------+-------+-------|--------+-------+-------+-------+-------+-------| 
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

/* DELETE THIS LINE TO UNCOMMENT (1/2) */
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

void oled_show_state(void) {
    // Write host Keyboard LED Status to OLEDs
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock    ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPS ") : PSTR("     "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRL\n") : PSTR("\n"), false);
}

bool oled_task_user(void) {
#if 1 

    uint16_t mods = get_mods();
    oled_write_P( (mods & MOD_MASK_SHIFT) ? PSTR("Shift ") : PSTR("      "), false);
    oled_write_P( (mods & MOD_MASK_GUI) ? PSTR("Gui ") : PSTR("    "), false);
    oled_write_P( (mods & MOD_MASK_ALT) ? PSTR("Alt ") : PSTR("    "), false);
    oled_write_P( (mods & MOD_MASK_CTRL ) ? PSTR("Ctl ") : PSTR("    "), false);
    oled_write_P(PSTR("\n"), false);

    if (is_keyboard_left()) {
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("Base "), false);
                oled_show_state();
                oled_write_P(PSTR("Tb  Q   W   E   R  T\n"), false);
                oled_write_P(PSTR("CE  A   S   D   F  G\n"), false);
                oled_write_P(PSTR("S(  Z   X   C   V  B\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav  "), false);
                oled_show_state();
                oled_write_P(PSTR("Bt DB  EE  MU     WU\n"), false);
                oled_write_P(PSTR("CE __  ML  MD  MR WD\n"), false);
                oled_write_P(PSTR("S( __  WL  __  WR __\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym  "), false);
                oled_show_state();
                oled_write_P(PSTR("`   1   2   3   4  5\n"), false);
                oled_write_P(PSTR("~   !   @   #   $  %\n"), false);
                oled_write_P(PSTR("|  \\   =   +   {   [\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Func "), false);
                oled_show_state();
                oled_write_P(PSTR("Bt F9 F10 F11 F12 PS\n"), false);
                oled_write_P(PSTR("__ F5 F6  F7  F8 CAP\n"), false);
                oled_write_P(PSTR("__ F1 F2  F3  F4 SCL\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adj  "), false);
                oled_show_state();
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                break;
            default:
                oled_write_P(PSTR("Unk  "), false);
                oled_show_state();
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                break;
        }
    } else {
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("Base "), false);
                oled_show_state();
                oled_write_P(PSTR("Y  U  I  O  P  BS \n"), false);
                oled_write_P(PSTR("H  J  K  L  :  \" \n"), false);
                oled_write_P(PSTR("N  M  ,  .  /  SH)\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav  "), false);
                oled_show_state();
                oled_write_P(PSTR("PU HO UP EN V+ DEL\n"), false);
                oled_write_P(PSTR("PD LF DN RT V- INS\n"), false);
                oled_write_P(PSTR("WL B1 B2 WR MU PSC\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym  "), false);
                oled_show_state();
                oled_write_P(PSTR("6  7  8  9  0  +\n"), false);
                oled_write_P(PSTR("^  &  *  (  )  =\n"), false);
                oled_write_P(PSTR("]  }  -  _  -  _\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Func "), false);
                oled_show_state();
                oled_write_P(PSTR("Pa    EE DB  Bt\n"), false);
                oled_write_P(PSTR("PS Sh Cl Alt Gui\n"), false);
                oled_write_P(PSTR("Nu WL    WR\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adj  "), false);
                oled_show_state();
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                break;
            default:
                oled_write_P(PSTR("Unk  "), false);
                oled_show_state();
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                oled_write_P(PSTR("\n"), false);
                break;
        }
    }


#if WPM_ENABLE
    int wpm = get_current_wpm();
    char line[20];
	  snprintf(line, 19, "\nWPM:%02d\n", wpm);
    oled_write_ln(line, false);
#endif

    return false;
#else
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev2.1\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {

        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
	static bool first=true;
	if (first) {
            oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
		oled_scroll_set_speed(4);
		first=false;
		oled_scroll_left();
	}
	if (! is_oled_scrolling()) oled_scroll_left();

    }
    return false;
#endif
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
/* DELETE THIS LINE TO UNCOMMENT (2/2) */
