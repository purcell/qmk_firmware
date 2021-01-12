#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNC,
  _NUMPAD,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
};

/*
  Bindings to consider:

  M-x
  C-a
  C-e
  M-C-x
  C-1
  M-1
  M-!
  M-%
  M-`
  C-<right>
  M-<up>
  M-S-<up>
  M-[
  M-{

 */

#define KC_GUI_BSP LGUI_T(KC_BSPC)
#define KC_LWR_EQL LT(_LOWER, KC_EQL)
#define KC_RAI_MIN LT(_RAISE, KC_MINS)
#define KC_CTL_SPC LCTL_T(KC_SPACE)
#define KC_ESC_CTL LCTL_T(KC_ESC)
#define KC_TAB_NUM LT(_NUMPAD, KC_TAB)
#define KC_FUNC MO(_FUNC)
#define KC_SUPER LCAG_T(KC_TRNS)
#define KC_SFT_ENT RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Hack for blanks
#define KC_ KC_TRNS

[_QWERTY] = LAYOUT_kc(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    TAB_NUM,    Q   ,    W   ,    E   ,    R   ,    T   ,    Y   ,    U   ,    I   ,   O    ,    P   ,  BSPC  ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    ESC_CTL,    A   ,    S   ,    D   ,    F   ,    G   ,    H   ,    J   ,    K   ,    L   ,  SCLN  ,  QUOT  ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    LSFT   ,    Z   ,    X   ,    C   ,    V   ,    B   ,    N   ,    M   ,  COMM  ,  DOT   ,  SLSH  , SFT_ENT,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    FUNC   ,  LCTL  ,  SUPER ,  LALT  , LWR_EQL, GUI_BSP, CTL_SPC, RAI_MIN,  LEFT  ,  DOWN  ,   UP   ,  RGHT
//└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
),

[_LOWER] = LAYOUT_kc(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
           ,        ,        ,        ,        ,        ,  PGUP  ,  HOME  ,   UP   ,   END  ,        ,   DEL  ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           ,        ,        ,        ,        ,        ,  PGDN  ,  LEFT  ,  DOWN  ,  RGHT  ,        ,  PIPE  ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           ,        ,        ,        ,        ,        ,        ,        ,  HOME  ,  PGDN  ,  PGUP  ,   END
//└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
),

[_RAISE] = LAYOUT_kc(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     GRV   ,    1   ,    2   ,    3   ,    4   ,    5   ,    6   ,    7   ,    8   ,    9   ,    0   ,   DEL  ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    TILD   ,  EXLM  ,   AT   ,  HASH  ,  DLR   ,  PERC  ,  CIRC  ,  AMPR  ,  ASTR  ,  LPRN  ,  RPRN  ,  BSLS  ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           ,        ,        ,        ,        ,        ,        ,  LBRC  ,  RBRC  ,  LCBR  ,  RCBR  ,        ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
//└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
),

[_FUNC] = LAYOUT_kc(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
           ,   F1   ,   F2   ,   F3   ,   F4   ,   F5   ,   F6   ,   F7   ,   F8   ,   F9   ,   F10  ,   F11  ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           ,        ,        ,        ,        ,        ,        ,   F4   ,   F5   ,   F6   ,        ,   F12  ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           ,        ,        ,        ,        ,        ,  F10   ,   F1   ,   F2   ,   F3   ,        ,        ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
//└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
),


[_NUMPAD] = LAYOUT_kc(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
           ,    1   ,    2   ,    3   ,    4   ,    5   ,    6   ,    7   ,    8   ,    9   ,    0   ,        ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           ,        ,        ,        ,        ,        ,        ,    4   ,    5   ,    6   ,        ,        ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           ,        ,        ,        ,        ,        ,    0   ,    1   ,    2   ,    3   ,        ,        ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           ,        ,        ,        ,        ,        ,        ,        ,    0   ,        ,        ,
//└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
),

//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_VOLD, KC_VOLU, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case KC_RAI_MIN:
    case KC_LWR_EQL:
      return false;
    default:
      return true;
  }
}

/* Local Variables: */
/* compile-command: "cd ../../../.. && make git-submodule && make planck/rev6:sanityinc:flash" */
/* End: */
