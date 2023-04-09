 /* Copyright 2021 Dane Evans
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
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H
//#define NUMPAD
#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
	{1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_NUMPAD(hsv)     \
	{35+15, 5, hsv},\
	  {35+22, 3, hsv},\
	  {35+27, 3, hsv}
#define SET_NUMROW(hsv) \
	{10, 2, hsv}, \
		{20, 2, hsv}, \
		{30, 2, hsv}, \
	  {35+ 10, 2, hsv}, \
	  {35+ 20, 2, hsv}, \
	  {35+ 30, 2, hsv}
#define SET_INNER_COL(hsv)	\
	{33, 4, hsv}, \
	  {35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
	{7, 4, hsv}, \
	  {35+ 7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
	{25, 2, hsv}, \
	  {35+ 25, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
		{1, 6, hsv}, \
    {35+1, 6, hsv}, \
		{7, 4, hsv}, \
	  {35+ 7, 4, hsv}, \
		{25, 2, hsv}, \
	  {35+ 25, 2, hsv}


enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    _SYMBL,
    _NAV,
    _FUNC,
    _ADJ,
#ifdef NUMPAD
    _NUMPD,
#endif
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_SYMBL,
    KC_FUNC,
    KC_NAV,
    KC_ADJ
};
#define CTLESC LCTL_T(KC_ESC)
#define SPACE_1 LT(_SYMBL, KC_SPC)
#define CA_DEL LCA(KC_DEL)
#define SCRLCK LGUI(KC_L)
#define CTLGR LGUI(LCTL(KC_RIGHT))
#define CTLGL LGUI(LCTL(KC_LEFT))
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, 
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, 
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
//|--------+--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------+--------|
   SC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,  KC_FUNC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC,
//|--------+--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------+--------|
                 KC_LGUI, KC_LALT, KC_NAV,  KC_SYMBL,  KC_ENT,          KC_ENT,  KC_SPC,   KC_NAV, KC_ADJ,  KC_RGUI
//              \--------+--------+--------+---------+-------|        |--------+---------+--------+---------+-------/
),

[_SYMBL] = LAYOUT(
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, 
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL,  
//|--------+--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------+--------|
   _______, KC_PIPE, KC_BSLS,  KC_PLUS, KC_LCBR, KC_LBRC, _______,  _______, KC_RBRC, KC_RCBR, KC_MINS, KC_UNDS, KC_MINS, _______,
//|--------+--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------+--------|
                 _______, _______, _______, _______, _______,          _______, _______,  _______, _______, _______
//              \--------+--------+--------+---------+-------|        |--------+---------+--------+---------+-------/
),
[_NAV] = LAYOUT(
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   _______, KC_NO,    KC_NO,   KC_NO,  DB_TOGG, QK_BOOT,                    QK_BOOT,  DB_TOGG, KC_NO  , KC_NO,   KC_NO,   CA_DEL,
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   _______, KC_NO,   KC_NO,   KC_MS_U, KC_NO,   KC_WH_U,                    KC_PGUP,  KC_HOME, KC_UP  , KC_END,  KC_VOLU, KC_DEL , 
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   _______, KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                    KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS , 
//|--------+--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------+--------|
   _______, KC_NO,   CTLGL,   KC_NO,   CTLGR,   KC_NO  ,  _______,  _______, CTLGL,   KC_BTN1, KC_BTN2, CTLGR,   KC_MUTE, _______, 
//|--------+--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------+--------|
                 _______, _______, _______, _______, _______,          _______, _______,  _______, _______, _______
//              \--------+--------+--------+---------+-------|        |--------+---------+--------+---------+-------/
),
[_FUNC] = LAYOUT(
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   QK_BOOT, KC_NO,   KC_NO,   KC_NO,   DB_TOGG, QK_BOOT,                    QK_BOOT, DB_TOGG,  KC_NO,   KC_NO  , KC_NO  , QK_BOOT,
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,                    KC_PAUSE, XXXXXXX, XXXXXXX, QK_BOOT, DB_TOGG, _______,
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_CAPS,                    KC_PSCR , KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
//|--------+--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------+--------|
   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_SCRL, _______,   _______, KC_NUM,  XXXXXXX, XXXXXXX, XXXXXXX, KC_NO  ,_______, 
//|--------+--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------+--------|
                 _______, _______, _______, _______, _______,          _______, _______,  _______, _______, _______
//              \--------+--------+--------+---------+-------|        |--------+---------+--------+---------+-------/
),
  [_ADJ] = LAYOUT(
//|--------+--------+--------+--------+--------+--------|                  |-------+-------+-------+-------+-------+--------| 
   QK_BOOT ,DB_TOGG , XXXXXXX, XXXXXXX, XXXXXXX, QK_RBT,                    QK_RBT ,XXXXXXX,XXXXXXX,_______,DB_TOGG,QK_BOOT,
//|--------+--------+--------+--------+--------+--------|                  |-------+-------+-------+-------+-------+--------| 
   QK_BOOT ,DB_TOGG , XXXXXXX, XXXXXXX, XXXXXXX, QK_RBT,                    QK_RBT ,XXXXXXX,XXXXXXX,_______,DB_TOGG,QK_BOOT,
//|--------+--------+--------+--------+--------+--------|                  |-------+-------+-------+-------+-------+--------| 
   _______, _______ , _______, _______, _______, _______,                   RGB_TOG,RGB_SAI,RGB_HUI,RGB_VAI,RGB_MOD,XXXXXXX,
//|--------+--------+--------+--------+--------+--------+--------||--------+-------+-------+-------+-------+-------+--------|
   _______, _______ , _______, _______, _______, _______,_______,   _______,_______,RGB_SAD,RGB_HUD,RGB_VAD,RGB_RMOD,QK_RBT,
//|--------+--------+--------+--------+--------+--------+--------||--------+-------+-------+-------+-------+-------+--------|
                 _______, _______, _______, _______, _______,          _______, _______,  _______, _______, _______
//              \--------+--------+--------+---------+-------|        |--------+---------+--------+---------+-------/
#ifdef NUMPAD
) ,
[_NUMPD] = LAYOUT(
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    _______, KC_NUM,  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,                    KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                    KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_EQL,  KC_PIPE,
//|--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------| 
   XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, _______,  _______, KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_SLSH, _______,
//|--------+--------+--------+--------+--------+--------+--------||--------+--------+--------+--------+--------+--------+--------|
                 _______, _______, _______, _______, _______,          _______, _______,  _______, _______, _______
//              \--------+--------+--------+---------+-------|        |--------+---------+--------+---------+-------/
#endif
)
};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_RED)

);

// _NUM,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_TEAL)

);
// _SYMBOL,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_BLUE)

    );
// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PURPLE)
);

//_NUMPD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_INDICATORS(HSV_ORANGE),
    SET_UNDERGLOW(HSV_ORANGE),
	SET_NUMPAD(HSV_BLUE),
    {7, 4, HSV_ORANGE},
    {25, 2, HSV_ORANGE},
    {35+6, 4, HSV_ORANGE},
    {35+25, 2, HSV_ORANGE}
    );
// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_GREEN),
	SET_NUMROW(HSV_GREEN)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
	layer_num_lights,// overrides layer 1
	layer_symbol_lights,
    layer_command_lights,
	layer_numpad_lights,
	layer_switcher_lights  // Overrides other layers
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));

	rgblight_set_layer_state(1, layer_state_cmp(state, _SYMBL));
	rgblight_set_layer_state(2, layer_state_cmp(state, _NAV));
	rgblight_set_layer_state(3, layer_state_cmp(state, _ADJ));
#ifdef NUMPAD
	rgblight_set_layer_state(4, layer_state_cmp(state, _NUMPD));
#endif
    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

	rgblight_mode(10);// haven't found a way to set this in a more useful way

}
#endif

#ifdef OLED_ENABLE
#include <string.h>
char lines[15][6];
static void oled_draw(void) {
    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            strcpy(lines[0], "");
            break;
        case _NAV:
            strcpy(lines[0], "Nav");
            break;
        case _FUNC:
            strcpy(lines[0], "Func");
            break;
        case _SYMBL:
            strcpy(lines[0], "Symb");
            break;
        case _ADJ:
            strcpy(lines[0], "Adj");
            break;
#ifdef NUMPAD
        case _NUMPD:
            strcpy(lines[0], "Nump");
            break;
#endif
        default:
            strcpy(lines[0], "Undf");
    }
    uint16_t mods = get_mods();
    if (mods & MOD_MASK_CTRL ) strcpy(lines[1], "Ctrl"); else lines[1][0] = '\0';
    if (mods & MOD_MASK_ALT  ) strcpy(lines[2], "Alt");  else lines[2][0] = '\0';
    if (mods & MOD_MASK_SHIFT) strcpy(lines[3], "Shft"); else lines[3][0] = '\0';
    if (mods & MOD_MASK_GUI  ) strcpy(lines[4], "Win");  else lines[4][0] = '\0';

    led_t ledstate = host_keyboard_led_state();
    if (ledstate.caps_lock)   strcpy(lines[5], "CAPS"); else lines[5][0] = '\0';
    if (ledstate.scroll_lock) strcpy(lines[6], "SCRL"); else lines[6][0] = '\0';
    if (ledstate.compose)     strcpy(lines[7], "CMPS"); else lines[7][0] = '\0';
    if (ledstate.num_lock)    strcpy(lines[8], "NUM");  else lines[8][0] = '\0';

#ifdef WPM_ENABLE
    int wpm = get_current_wpm();
    if (wpm > 0) {
	snprintf(lines[9], 6, "W:%02d\n", wpm);
    } else {
	strcpy(lines[9], "\n");
    }
#endif
    for (short i=0 ; i < 15 ; i++) {
	    oled_write_ln(lines[i], false);
    }
}

static const char PROGMEM logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0,
    0xF0, 0xF8, 0xF8, 0xFC, 0xFC, 0xFE, 0xFE, 0xFF, 0x7F, 0x7F, 0x7F, 0x7F,
    0x7F, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0xFC, 0xFC,
    0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFC, 0xFC, 0xF8, 0xF8, 0xF8, 0xF8, 0xF0, 0xF3, 0xF3,
    0xE3, 0xE3, 0xC3, 0xC3, 0xC3, 0x83, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0xE0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC, 0xFE, 0xFE, 0xFE, 0x7E, 0x7E,
    0x7E, 0xFE, 0xFE, 0xFE, 0xFC, 0xFC, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x00,
    0x00, 0x7E, 0x7E, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x7E, 0x7E, 0x7E, 0x7E, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0,
    0xF8, 0xFC, 0xFC, 0xFE, 0xFE, 0xFE, 0xFF, 0x7F, 0x7F, 0x7F, 0x7F, 0xFE,
    0xFE, 0xFE, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE1, 0xE1, 0xE3, 0xE3, 0x83, 0x07,
    0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x1F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xBD, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3D, 0x3F, 0x3F, 0x3F,
    0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07,
    0x0F, 0x1F, 0x3F, 0x3F, 0x7F, 0x7F, 0x7F, 0xFE, 0xFE, 0xFC, 0xFC, 0xFC,
    0xFC, 0xFC, 0xFE, 0xFF, 0x7F, 0x7F, 0x3F, 0x3F, 0x1F, 0x0F, 0x07, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x7F,
    0x7F, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0x7F, 0x7F, 0x3F, 0x3F, 0x1F,
    0x0F, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x07, 0x0F, 0x1F, 0x3F, 0x3F, 0x7F, 0x7F, 0x7F, 0xFF, 0xFE,
    0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x1F, 0x0F, 0x03,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

static void render_logo(void) {
    static bool first=true;
    if (first) {
        oled_write_raw_P(logo, sizeof(logo));
        oled_scroll_set_speed(4);
        first=false;
        oled_scroll_left();
    }
    if (! is_oled_scrolling()) oled_scroll_left();
}
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_draw();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_SYMBL:
            if (record->event.pressed) {
                layer_on(_SYMBL);
            } else {
                layer_off(_SYMBL);
            }
            return false;
        case KC_NAV:
            if (record->event.pressed) {
                layer_on(_NAV);
                update_tri_layer(_FUNC, _NAV, _ADJ);
            } else {
                layer_off(_NAV);
                update_tri_layer(_FUNC, _NAV, _ADJ);
            }
            return false;
        case KC_FUNC:
            if (record->event.pressed) {
                layer_on(_FUNC);
                update_tri_layer(_FUNC, _NAV, _ADJ);
            } else {
                layer_off(_FUNC);
                update_tri_layer(_FUNC, _NAV, _ADJ);
            }
            return false;
        case KC_ADJ:
            if (record->event.pressed) {
                layer_on(_ADJ);
            } else {
                layer_off(_ADJ);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
		} else if (index == 1) {
			switch (get_highest_layer(layer_state)) {
				case _QWERTY:
					if (clockwise) {
						tap_code(KC_WH_D);
					} else {
						tap_code(KC_WH_U);
					}
				break;
			case _NAV:
			case _SYMBL:
					if (clockwise) {
						tap_code(KC_DOWN);
					} else {
						tap_code(KC_UP);
					}
				break;
			default:
					if (clockwise) {
						tap_code(KC_WH_D);
					} else {
						tap_code(KC_WH_U);
					}
				break;
		}
    }
    return true;
}

#endif
