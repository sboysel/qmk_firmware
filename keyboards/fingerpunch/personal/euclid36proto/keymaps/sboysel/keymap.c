#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _NAV,
    _NUM,
    _SYM,
    _FUN,
    _MEDIA
};

#define LT_ESC LT(_MEDIA, KC_ESC)
#define LT_SPC LT(_NAV, KC_SPC)
#define LT_TAB LT(_NAV, KC_TAB)
#define LT_ENT LT(_SYM, KC_ENT)
#define LT_BSPC LT(_NUM, KC_BSPC)
#define LT_DEL LT(_FUN, KC_DEL)

#define MT_A LGUI_T(KC_A)
#define MT_S LALT_T(KC_S)
#define MT_D LCTL_T(KC_D)
#define MT_F LSFT_T(KC_F)
#define MT_J LSFT_T(KC_J)
#define MT_K LCTL_T(KC_K)
#define MT_L LALT_T(KC_L)
#define MT_QUOT LGUI_T(KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.             ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   '  |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'             `----------------------------------'
 *                      ,-----------------.   ,------------------.
 *                      | ESC | SPC | TAB |   | ENT | BSPC | DEL |
 *                      `-----------------'   `------------------'
 */
[_QWERTY] = LAYOUT_euclid(
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  MT_A,    MT_S,    MT_D,    MT_F,    KC_G,         KC_H,    MT_J,    MT_K,    MT_L,    MT_QUOT,
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                    LT_ESC,  LT_SPC,  LT_TAB,       LT_ENT,  LT_BSPC, LT_DEL
),

/* NAV
 *
 * ,----------------------------------.             ,----------------------------------.
 * |      |      |      |      |      |             |      |      |      |      |      |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * | GUI  | ALT  | CTRL | SHFT |      |             |      | LEFT | DOWN |  UP  | RGHT |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |      |      |      |      |      |             |      | HOME | PGDN | PGUP | END  |
 * `----------------------------------'             `----------------------------------'
 *                      ,-----------------.    ,-----------------.
 *                      |     | NAV |     |    |     |     |     |
 *                      `-----------------'    `-----------------'
 */
[_NAV] = LAYOUT_euclid(
  QK_BOOT, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
  _______, _______, _______, _______, _______,      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                    _______, _______, _______,      KC_ENT,  KC_BSPC, KC_DEL
),

/* NUM
 *
 * ,----------------------------------.             ,----------------------------------.
 * |   [  |   7  |   8  |  8   |   ]  |             |      |      |      |      |      |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |   ;  |   4  |   5  |  6   |   =  |             |      | SHFT | CTRL | ALT  | GUI  |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |   `  |   1  |  2   |  3   |   \  |             |      |      |      |      |      |
 * `----------------------------------'             `----------------------------------'
 *                      ,-----------------.    ,-----------------.
 *                      |  .  |  0  |  -  |    |     | NUM |     |
 *                      `-----------------'    `-----------------'
 */
[_NUM] = LAYOUT_euclid(
  KC_LBRC,  KC_7,  KC_8,   KC_9,  KC_RBRC,      _______, _______, _______, _______, _______,
  KC_SCLN,  KC_4,  KC_5,   KC_6,  KC_EQL,       _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  KC_GRAVE, KC_1,  KC_2,   KC_3,  KC_BSLS,      _______, _______, _______, _______, _______,
                   KC_DOT, KC_0,  KC_MINS,      _______, _______, _______
),

/* SYM 
 *
 * ,----------------------------------.             ,----------------------------------.
 * |   {  |   &  |   *  |  (   |   }  |             |      |      |      |      |      |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |   :  |   $  |   %  |  ^   |   +  |             |      | SHFT | CTRL | ALT  | GUI  |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |   ~  |   !  |  @   |  #   |   |  |             |      |      |      |      |      |
 * `----------------------------------'             `----------------------------------'
 *                    ,-------------------.    ,-----------------.
 *                    |  (   |  )   |  _  |    | SYM |     |     |
 *                    `-------------------'    `-----------------'
 */
[_SYM] = LAYOUT_euclid(
  KC_LCBR,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RCBR,      _______, _______, _______, _______, _______,
  KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_PLUS,      _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  KC_TILDE, KC_EXLM,  KC_AT,    KC_HASH,  KC_PIPE,      _______, _______, _______, _______, _______,
                      KC_LPRN,  KC_RPRN,  KC_UNDS,      _______, _______, _______
)
};
