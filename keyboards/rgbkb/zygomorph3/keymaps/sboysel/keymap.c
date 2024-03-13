/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum sol_layers {
  _QWERTY,
  _NAV,
  _FUN,
  _SYM,
  _NUM
};

enum zygo_keycodes {
  RGB_RST
};

#define CMD_A      CMD_T(KC_A)
#define ALT_S      ALT_T(KC_S)
#define CTL_D      CTL_T(KC_D)
#define SFT_F      SFT_T(KC_F)
#define NAV        LT(_NAV, KC_SPC)
#define FUN        LT(_FUN, KC_TAB)
#define SYM        LT(_SYM, KC_ENT)
#define NUM        LT(_NUM, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* QWERTY Layout
  ┌──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┐
  |      |      |      |      |      |      |  |      |      |      |      |      |      |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |   Q  |   W  |   E  |   R  |   T  |      |  |      |   Y  |   U  |   I  |   O  |   P  |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |   A  |   S  |   D  |   F  |   G  |      |  |      |   H  |   J  |   K  |   L  |   '  |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |   Z  |   X  |   C  |   V  |   B  |      |  |      |   N  |   M  |   ,  |   .  |   /  |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |      |      |      |  ESC | NAV  | FUN  |  |  SYM |  NUM | DEL  |      |      |      |
  └──────┴──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┴──────┘
  ┌──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┐
  │      |      |      |      |      |      |  |      |      |      |      |      |      │
  └──────┴──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┴──────┘
  ┌──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┐
  │      |      |      |      |      |                |      |      |      |      |      │
  └──────┴──────┴──────┴──────┴──────┘                └──────┴──────┴──────┴──────┴──────┘
  */
  [_QWERTY] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       _______,    _______,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
    CMD_A,      ALT_S,      CTL_D,      SFT_F,      KC_G,       _______,    _______,    KC_H,       KC_J,       KC_K,       KC_L,       KC_QUOT,
    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       _______,    _______,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,   
    _______,    _______,    _______,    KC_ESC,     NAV,        FUN,        SYM,        NUM,        KC_DEL,     _______,    _______,    _______,

    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______
  ), 

  /*  NAV Layout
  ┌──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┐
  |      |      |      |      |      |      |  |      |      |      |      |      |      |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |      |      |      |      |      |      |  |      |      |      |      |      |      |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |  CMD |  ALT |  CTL |  SFT |      |      |  |      |      | LEFT | DOWN |  UP  | RIGHT|
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |      |      |      |      |      |      |  |      |      | HOME | PGDN | PGUP |  END |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |      |      |      |  ESC |      | FUN  |  |  SYM |  NUM | DEL  |      |      |      |
  └──────┴──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┴──────┘
  ┌──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┐
  │      |      |      |      |      |      |  |      |      |      |      |      |      │
  └──────┴──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┴──────┘
  ┌──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┐
  │      |      |      |      |      |                |      |      |      |      |      │
  └──────┴──────┴──────┴──────┴──────┘                └──────┴──────┴──────┴──────┴──────┘
  */
  [_NAV] = LAYOUT(
    _______,    _______,    _______,    _______,    RGB_TOG,    RGB_MOD,    QK_BOOT,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_LCMD,    KC_LALT,    KC_LCTL,    KC_LSFT,    _______,    _______,    _______,    _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,
    _______,    _______,    _______,    _______,    KC_SPC,     KC_TAB,     KC_ENT,     KC_BSPC,    KC_DEL,     _______,    _______,    _______,

    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______
  ),

    /*  FUN Layout
  ┌──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┐
  |      |      |      |      |      |      |  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |      |      |      |      |      |      |  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |  CMD |  ALT |  CTL |  SFT |      |      |  |      |      |      |      |      |      |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |      |      |      |      |      |      |  |      |      |      |      |      |      |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |      |      |      |  ESC |  SPC |      |  |  ENT | BSPC |  DEL |      |      |      |
  └──────┴──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┴──────┘
  ┌──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┐
  │      |      |      |      |      |      |  |      |      |      |      |      |      │
  └──────┴──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┴──────┘
  ┌──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┐
  │      |      |      |      |      |                |      |      |      |      |      │
  └──────┴──────┴──────┴──────┴──────┘                └──────┴──────┴──────┴──────┴──────┘
  */
  [_FUN] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,
    _______,    _______,    _______,    _______,    _______,    _______,    KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
    KC_LCMD,    KC_LALT,    KC_LCTL,    KC_LSFT,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, 
    _______,    _______,    _______,    KC_ESC,     KC_SPC,     _______,    KC_ENT,     KC_BSPC,    KC_DEL,     _______,    _______,    _______,

    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______
  ),

  /*  SYM Layout
  ┌──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┐
  |      |      |      |      |      |      |  |      |      |      |      |      |      |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |   {  |   &  |   *  |   (  |   }  |      |  |      |      |      |      |      |      |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |   :  |   $  |   %  |   ^  |   +  |      |  |      |      |  SFT |  CTL |  ALT |  CMD |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |   ~  |   !  |   @  |   #  |   |  |      |  |      |      |      |      |      |      |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |      |      |      |   (  |   )  |   _  |  |  ENT |      | DEL  |      |      |      |
  └──────┴──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┴──────┘
  ┌──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┐
  │      |      |      |      |      |      |  |      |      |      |      |      |      │
  └──────┴──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┴──────┘
  ┌──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┐
  │      |      |      |      |      |                |      |      |      |      |      │
  └──────┴──────┴──────┴──────┴──────┘                └──────┴──────┴──────┴──────┴──────┘
  */
  [_SYM] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_LCBR,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RCBR,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_COLN,     KC_DLR,    KC_PERC,    KC_CIRC,    KC_PLUS,    _______,    _______,    _______,    KC_LSFT,   KC_LCTRL,    KC_LALT,    KC_LGUI,
    KC_TILD,    KC_EXLM,    KC_AT,      KC_HASH,    KC_PIPE,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   
    _______,    _______,    _______,    KC_LPRN,    KC_RPRN,    KC_UNDS,    _______,    KC_BSPC,    KC_DEL,     _______,    _______,    _______,

    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______
  ),

  /*  NUM Layout
  ┌──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┐
  |      |      |      |      |      |      |  |      |      |      |      |      |      |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |   [  |   7  |   8  |   9  |   ]  |      |  |      |      |      |      |      |      |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |   ;  |   4  |   5  |   6  |   =  |      |  |      |      |  SFT |  CTL |  ALT |  CMD |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |   `  |   1  |   2  |   3  |   \  |      |  |      |      |      |      |      |      |
  ├──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┤
  |      |      |      |   .  |   0  |   -  |  |  ENT |      | DEL  |      |      |      |
  └──────┴──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┴──────┘
  ┌──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┐
  │      |      |      |      |      |      |  |      |      |      |      |      |      │
  └──────┴──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┴──────┘
  ┌──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┐
  │      |      |      |      |      |                |      |      |      |      |      │
  └──────┴──────┴──────┴──────┴──────┘                └──────┴──────┴──────┴──────┴──────┘
  */
  [_NUM] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_LBRC,    KC_7,       KC_8,       KC_9,       KC_RBRC,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_SCLN,    KC_4,       KC_5,       KC_6,       KC_EQL,     _______,    _______,    _______,    KC_LSFT,   KC_LCTRL,    KC_LALT,    KC_LGUI,
    KC_GRV,     KC_1,       KC_2,       KC_3,       KC_BSLS,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   
    _______,    _______,    _______,    KC_DOT,     KC_0,       KC_MINUS,    KC_ENT,    _______,    KC_DEL,     _______,    _______,    _______,

    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
        case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
            }
            return false;
        default:
            return true;
    }
}