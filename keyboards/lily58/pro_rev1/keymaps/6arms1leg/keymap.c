#include QMK_KEYBOARD_H

#if defined(KEYMAP_EURKEY)
#include "keymap_eurkey.h"
// Keycodes for umlauts and eszett
#define UML_AE EU_ADIA
#define UML_OE EU_ODIA
#define UML_UE EU_UDIA
#define GER_SZ EU_SS
#define EU_EUR EU_EURO
// Keycodes for dead keys
enum custom_keycodes {
  MC_QUOT = KC_QUOT,
  MC_GRV = KC_GRV
};
#else
// Keycodes for umlauts and eszett
#define UML_AE RALT(KC_Q)
#define UML_OE RALT(KC_P)
#define UML_UE RALT(KC_Y)
#define GER_SZ RALT(KC_S)
#define EU_EUR RALT(KC_5)
// Keycodes for dead keys
enum custom_keycodes {
  MC_QUOT = SAFE_RANGE,
  MC_GRV
};
#endif /* defined(KEYMAP_EURKEY) */

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| LOWER |    | RAISE |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCTRL | LGUI | LAlt | /Space  /       \Enter \  | RAlt |BackSP|RCTRL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  MC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, MO(_LOWER),    MO(_RAISE),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,                     KC_ENT, KC_RALT, KC_BSPC, KC_RCTL
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |      |      |      |      |      |                    |      |  Ü   |      |  Ö   |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------| LOWER |    | RAISE |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|      |      |   [  |   ]  |   \  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCTRL | LGUI | LAlt | /Space  /       \Enter \  | RAlt | DEL  |RCTRL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, UML_UE,  XXXXXXX, UML_OE,  XXXXXXX, KC_F12,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, _______,
                      _______, _______, _______, _______,                 _______,  _______, KC_DEL, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  | F5   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |      |      |   €  | PgUp |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Ä  |   ß  | Home |      | End  |-------.    ,-------| Home |PgDown| PgUp | End  |      |      |
 * |------+------+------+------+------+------| LOWER |    | RAISE |------+------+------+------+------+------|
 * |LShift|      |      |      |PgDown|      |-------|    |-------|      |      |      |      |      |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCTRL | MENU | LAlt | /Space  /       \Enter \  | RAlt |BackSP|RCTRL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, EU_EUR,  KC_PGUP, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, UML_AE,  GER_SZ,  KC_HOME, XXXXXXX, KC_END,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, _______,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      _______, KC_MENU, _______, _______,                _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------| LOWER |    | RAISE |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCTRL | LGUI | LAlt | /Space  /       \Enter \  | RAlt |BackSP|RCTRL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______,                _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

#if defined(KEYMAP_EURKEY)
  /* Do nothing */
#else
  switch (keycode) {
    case MC_QUOT: {
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));
      }
      break;
    }
    case MC_GRV: {
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_SPC));
      }
      break;
    }
  }
#endif /* defined(KEYMAP_EURKEY) */

  return true;
}
