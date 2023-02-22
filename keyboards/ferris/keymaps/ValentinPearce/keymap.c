// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "keymap_canadian_multilingual.h"
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _COLEMAK_DH,
  _NUMPAD,
  _NAV,
  _SYMBOL,
  _FUN
};

enum ferris_tap_dances {
  TD_Q_ESC
};

#define KC_GUTA GUI_T(KC_TAB)
#define KC_CLGV CTL_T(KC_GRV)
#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_RLSH RSFT_T(KC_SLSH)
// Layer Switching on hold
#define KC_SPM1 LT(1, KC_SPC)
#define KC_TBM2 LT(2, KC_TAB)
#define KC_ENM3 LT(3, KC_ENT)
#define KC_BSM4 LT(4, KC_BSPC)
// Home row mods
#define MT_SUA  MT(MOD_LGUI, CA_A)
#define MT_ALR  MT(MOD_LALT, CA_R)
#define MT_SHS  MT(MOD_LSFT, CA_S)
#define MT_CTT  MT(MOD_LCTL, CA_T)
#define MT_HPG  MT(MOD_HYPR, CA_G)
#define MT_SUO  MT(MOD_LGUI, CA_O)
#define MT_ALI  MT(MOD_LALT, CA_I)
#define MT_SHE  MT(MOD_LSFT, CA_E)
#define MT_CTN  MT(MOD_LCTL, CA_N)
#define MT_HPM  MT(MOD_HYPR, CA_M)

// Cosmetics
#define __NONE__ KC_NO   // Alias to make it eight wide

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT( /* COLEMAK-DH */
TD_Q_ESC,    CA_W,    CA_F,    CA_P,    CA_B,            CA_J,    CA_L,     CA_U,    CA_Y, CA_SCLN,
  MT_SUA,  MT_ALR,  MT_SHS,  MT_CTT,  MT_HPG,          MT_HPM,  MT_CTN,   MT_SHE,  MT_ALI,  MT_SUO,
    CA_Z,    CA_X,    CA_C,    CA_D,    CA_V,            CA_K,    CA_H,  CA_COMM,  CA_DOT, CA_SLSH,
                                     KC_TBM2, KC_SPM1, KC_ENM3, KC_BSM4
  ),

  [_NUMPAD] = LAYOUT( /* [> NUMPAD <] */
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    QK_GESC, KC_HOME, KC_PGDN, KC_PGUP, KC_END,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ENT,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  
  ),

  [_NAV] = LAYOUT( /* [> NAV <] */
    KC_ESC  ,KC_TRNS ,KC_TRNS  ,KC_TRNS  ,KC_TRNS,    __NONE__,KC_HOME ,KC_UP   ,KC_END  ,KC_PGUP,
    KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS  ,KC_TRNS,    __NONE__,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_PGDN,
    KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS  ,KC_TRNS,    CA_CCED ,CA_EACU ,CA_EGRV ,CA_AGRV ,CA_UGRV,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_SYMBOL] = LAYOUT( /* [> SYMBOL <] */
      CA_PERC ,CA_CIRC ,CA_DLR  ,CA_EURO ,__NONE__,    CA_QUES ,CA_LCBR ,CA_RCBR ,CA_AT   ,CA_HASH ,
      CA_SLSH ,CA_ASTR ,CA_MINS ,CA_PLUS ,CA_BSLS ,    __NONE__,CA_LPRN ,CA_RPRN ,KC_LT   ,KC_GT   ,
      CA_PIPE ,CA_AMPR ,CA_EXLM ,CA_EQL  ,CA_LABK ,    CA_RABK ,CA_LBRC ,CA_RBRC ,CA_TILD ,CA_GRV  ,
                                    KC_TRNS, CA_UNDS, KC_TRNS, KC_TRNS
  ),

  [_FUN] = LAYOUT( /* [> NAV <] */
    KC_ESC   ,KC_F7 ,KC_F8  ,KC_F9  ,KC_F12,    KC_TRNS,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS,
    __NONE__ ,KC_F4 ,KC_F5  ,KC_F6  ,KC_F11,    KC_TRNS,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS,
    __NONE__ ,KC_F1 ,KC_F2  ,KC_F3  ,KC_F10,    KC_TRNS,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(CA_Q, KC_ESC)
};
