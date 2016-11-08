#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  `|BSp|
     * |-----------------------------------------------------------|
     * |Fn3  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|Fn1|  '|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn0|
     * |-----------------------------------------------------------'
     * |Fn2  |Gui|Alt  |         Space         |Alt  |Gui|   |Fn3  |
     * `-----------------------------------------------------------'
     */
    [0] = \
    KEYMAP(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS, GRV, \
           FN3, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC, \
           LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   FN1, QUOT,ENT,  \
           LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,FN0, \
           FN2,  LGUI,LALT,          SPC,                RALT,RGUI,NO, FN3),

    /* Layer 1: HHKB mode (HHKB Fn)
     * ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   |Backs|
     * |-----------------------------------------------------------|
     * |      |VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |  +|  -|End|PgD|Dow|      |   |
     * `-----------------------------------------------------------'
     * |     |Gui|Alt  |         Space         |Alt  |Gui|   |     |
     * `-----------------------------------------------------------'
     */ 
    [1] = \
    KEYMAP(PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,   \
           CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS, UP, TRNS, BSPC,      \
           TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT,PENT,            \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS,END, PGDN,DOWN,TRNS,TRNS,            \
           TRNS,TRNS,TRNS,          TRNS,               TRNS,TRNS,TRNS,TRNS),

    /* Layer 2: Semi-VI
     * ,-----------------------------------------------------------.
     * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |     |Fn5|Fn6|End|   |   |Hom|PgU|PgD|End|   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |Hom|   |PgD|   |   |Lef|Dow| Up|Rig|   |   |Enter   |
     * |-----------------------------------------------------------|
     * |        |   |Del|   |   |   |App|End|Hom|   |   |      |   |
     * `-----------------------------------------------------------'
     * |     |   |     |                       |     |   |   |     |
     * `-----------------------------------------------------------'
     */ 
    [2] = \
    KEYMAP(TRNS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,   \
           TRNS,FN5 ,FN6 ,END ,TRNS,TRNS,HOME,PGDN,PGUP,END ,TRNS,TRNS,TRNS, TRNS,      \
           TRNS,HOME,TRNS,PGDN,TRNS,TRNS,LEFT,DOWN,  UP,RGHT,TRNS,TRNS,TRNS,            \
           TRNS,TRNS,DEL ,TRNS,TRNS,TRNS,APP ,END ,HOME,TRNS,TRNS,TRNS,TRNS,            \
           TRNS,TRNS,TRNS,          TRNS,               TRNS,TRNS,TRNS,TRNS),

    /* Layer 3: Window Nav
     * ,-----------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |Del|
     * |-----------------------------------------------------------|
     * |     |Fn5|Fn6|   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |Fn7|Fn8|        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |      |   |
     * `-----------------------------------------------------------'
     * |     |   |     |                       |     |   |   |     |
     * `-----------------------------------------------------------'
     */ 
    [3] = \
    KEYMAP(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,DEL,   \
           TRNS,FN5 ,FN6 ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,      \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN7 ,FN8 ,TRNS,            \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,            \
           TRNS,TRNS,TRNS,          TRNS,               TRNS,TRNS,TRNS,TRNS)
};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_LAYER_TAP_KEY(2, KC_SCLN),
    [2] = ACTION_LAYER_MOMENTARY(2),
    [3] = ACTION_LAYER_TAP_KEY(3, KC_TAB),
    [4] = ACTION_LAYER_MOMENTARY(3),
    [5] = ACTION_MODS_KEY(MOD_LALT, KC_LEFT),
    [6] = ACTION_MODS_KEY(MOD_LALT, KC_RGHT),
    [7] = ACTION_MODS_KEY(MOD_LGUI | MOD_LCTL, KC_LEFT),
    [8] = ACTION_MODS_KEY(MOD_LGUI | MOD_LCTL, KC_RGHT)
};

