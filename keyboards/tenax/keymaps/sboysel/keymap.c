#include QMK_KEYBOARD_H

/* home row mods */
#define MT_A LGUI_T(KC_A)
#define MT_S LALT_T(KC_S)
#define MT_D LCTL_T(KC_D)
#define MT_F LSFT_T(KC_F)
#define MT_QUOT LGUI_T(KC_QUOT)
#define MT_L LALT_T(KC_L)
#define MT_K LCTL_T(KC_K)
#define MT_J LSFT_T(KC_J)

/* layer tap */
#define LT_SPC LT(1, KC_SPC)
#define LT_TAB LT(2, KC_TAB)
#define LT_ENT LT(3, KC_ENT)
#define LT_BSPC LT(4, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ' │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │ESC├───┐           ┌───┤DEL│
      *           └───┤SPC├───┐   ┌───┤BSP├───┘
      *               └───┤TAB│   │ENT├───┘
      *                   └───┘   └───┘
      */
    [0] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        MT_A,    MT_S,    MT_D,    MT_F,    KC_G,                       KC_H,    MT_J,    MT_K,    MT_L,    MT_QUOT,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_ESC,  LT_SPC, LT_TAB,     LT_ENT, LT_BSPC, KC_DEL
    ),
    /* FUN */
    [1] = LAYOUT_split_3x5_3(
        KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,   KC_NO,                      KC_PSCR, KC_F1,   KC_F4,   KC_F7,   KC_F10,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_CAPS,                    KC_ESC,  KC_F2,   KC_F5,   KC_F8,   KC_F11,
        KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_NO,                      KC_INS,  KC_F3,   KC_F6,   KC_F9,   KC_F12,
                                   KC_NO,   KC_NO,   KC_NO,     KC_NO,  KC_NO,   KC_NO
    ),
    /* NAV */
    [2] = LAYOUT_split_3x5_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                      KC_ESC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                   KC_NO,   KC_NO,   KC_NO,     KC_ENT, KC_BSPC, KC_DEL
    ),
    /* SYM */
    [3] = LAYOUT_split_3x5_3(
        KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                    KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                   KC_RPRN, KC_UNDS, KC_NO,     KC_NO,  KC_NO,   KC_NO
    ),
    /* NUM */
    [4] = LAYOUT_split_3x5_3(
        KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                     KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                   KC_0,    KC_MINS, KC_NO,     KC_NO,  KC_NO,   KC_NO
    )
};
