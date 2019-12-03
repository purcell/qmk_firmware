#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layers { QWERTY, LWR, RAI, NUM, MOU, ADJ};

#define KC_HIST_BK LGUI(KC_LBRC)
#define KC_HIST_FW LGUI(KC_RBRC)

#define KC_LOUDER KC__VOLUP
#define KC_QUIETER KC__VOLDOWN
#define KC_HUSH KC__MUTE

#define KC_LWR MO(LWR)
#define KC_RAI MO(RAI)
#define KC_NUM MO(NUM)
#define KC_MOU MO(MOU)
#define KC_ADJ MO(ADJ)

#define KC_TAB_NUM LT(NUM, KC_TAB)
#define KC_SFT_ENT RSFT_T(KC_ENT)
#define KC_CTL_SPC RCTL_T(KC_SPC)
#define KC_RAI_MIN LT(RAI, KC_MINS)
#define KC_LCAG_EQL LCAG_T(KC_EQL)

#define KC_RESET RESET
#define KC_RGB_TOG RGB_TOG

#define KC_A_SFT LSFT_T(KC_A)
#define KC_S_CTL LCTL_T(KC_S)
#define KC_D_ALT LALT_T(KC_D)
#define KC_F_GUI LGUI_T(KC_F)
#define KC_J_GUI RGUI_T(KC_J)
#define KC_K_ALT RALT_T(KC_K)
#define KC_L_CTL RCTL_T(KC_L)
#define KC_SCLN_SFT RSFT_T(KC_SCLN)

// Hack for blanks
#define KC_ KC_TRNS

// TODO: try oneshot modifiers, or even modifiers on the home row,
// e.g. https://geekhack.org/index.php?topic=95683.0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT_kc(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      GRV    ,   1    ,   2    ,   3    ,   4    ,   5    ,                              6    ,   7    ,   8    ,   9    ,   0    ,  BSPC  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     TAB_NUM ,   Q    ,   W    ,   E    ,   R    ,   T    ,                              Y    ,   U    ,   I    ,   O    ,   P    ,  BSLS  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      LCTL   , A_SFT  , S_CTL  , D_ALT  , F_GUI  ,   G    ,                              H    , J_GUI  , K_ALT  , L_CTL  ,SCLN_SFT,  QUOT  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      LSFT   ,   Z    ,   X    ,   C    ,   V    ,   B    , LBRC   ,          RBRC   ,   N    ,   M    , COMM   ,  DOT   ,  SLSH  ,SFT_ENT ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     LALT   ,  LWR   ,  LGUI  ,                  CTL_SPC ,RAI_MIN ,LCAG_EQL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Here it looks like I accidentally and independently invented the
  // right hand side of the "extend" layer mentioned at
  // https://colemakmods.github.io/ergonomic-mods/extend.html
  [LWR] = LAYOUT_kc(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      ESC    ,        ,        ,        ,        ,        ,                                   ,        ,        ,        ,        ,  DEL   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
             ,        ,        ,        ,        ,        ,                             PGUP  ,  HOME  ,  UP    ,  END   ,HIST_BK ,HIST_FW ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
             ,  ADJ   ,        ,        ,        ,        ,                             PGDN  ,  LEFT  ,  DOWN  ,  RGHT  ,        ,        ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             ,  MOU   ,        ,        ,        ,        ,        ,                 ,        ,        ,        ,        ,        ,        ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            ,        ,        ,                    BTN1  ,        ,
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [RAI] = LAYOUT_kc(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      ESC    ,  F1    ,  F2    ,  F3    ,  F4    ,  F5    ,                             F6    ,  F7    ,  F8    ,  F9    ,  F10   ,  F11   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
             ,        ,        ,        ,        ,        ,                                   ,        ,        ,        ,        ,  F12   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      TILD   ,  EXLM  ,  AT    ,  HASH  ,  DLR   ,  PERC  ,                             CIRC  ,  AMPR  ,  ASTR  ,  LPRN  ,  RPRN  ,        ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             ,        ,        ,        ,        ,        ,        ,                 ,        ,        ,        ,        ,        ,        ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            ,        ,        ,                          ,        ,
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [NUM] = LAYOUT_kc(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
             ,        ,        ,        ,        ,        ,                                   ,   7    ,   8    ,   9    ,  ASTR  ,        ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
             ,        ,        ,        ,        ,        ,                                   ,   4    ,   5    ,   6    ,  MINS  ,        ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
             ,        ,        ,        ,        ,        ,                                   ,   1    ,   2    ,   3    ,  PLUS  ,        ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             ,        ,        ,        ,        ,        ,        ,                 ,        ,   0    ,   0    ,        ,        ,        ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            ,        ,        ,                          ,        ,
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [MOU] = LAYOUT_kc(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
             ,        ,        ,        ,        ,        ,                             ESC   ,        ,        ,        ,        ,        ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
             ,        ,        ,        ,        ,        ,                             WH_U  ,        ,  MS_U  ,        ,        ,        ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
             ,        ,        ,        ,        ,        ,                             WH_D  ,  MS_L  ,  MS_D  ,  MS_R  ,        ,        ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             ,        ,        ,        ,        ,        ,        ,           BTN2  ,        ,        ,        ,        ,        ,        ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            ,        ,        ,                    BTN1  ,        ,
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [ADJ] = LAYOUT_kc(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
             ,        ,        ,        ,        ,        ,                                   ,        ,        ,        ,        ,        ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
             ,        ,        ,        ,        ,        ,                            LOUDER ,        ,        ,        ,        ,        ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
             ,        ,        ,        ,        ,        ,                           QUIETER ,  MRWD   , MPLY  ,  MFFD  ,        ,RGB_TOG ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             ,        ,        ,        ,        ,        ,        ,                 , HUSH   ,        ,        ,        ,        , RESET  ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            ,        ,        ,                          ,        ,
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

  /*
  [_EMPTY] = LAYOUT_kc(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
             ,        ,        ,        ,        ,        ,                                   ,        ,        ,        ,        ,        ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
             ,        ,        ,        ,        ,        ,                                   ,        ,        ,        ,        ,        ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
             ,        ,        ,        ,        ,        ,                                   ,        ,        ,        ,        ,        ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             ,        ,        ,        ,        ,        ,        ,                 ,        ,        ,        ,        ,        ,        ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            ,        ,        ,                          ,        ,
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  */

};


//////////////////////////////////////////////////////////////////////////////
// QMK user hooks
//////////////////////////////////////////////////////////////////////////////

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
  case ADJ: rgblight_sethsv_noeeprom_yellow(); break;
  case MOU: rgblight_sethsv_noeeprom_teal(); break;
  case NUM: rgblight_sethsv_noeeprom_pink(); break;
  case RAI: rgblight_sethsv_noeeprom_red(); break;
  case LWR: rgblight_sethsv_noeeprom_green(); break;
  default: //  for any other layers, or the default layer
    rgblight_sethsv_noeeprom_purple(); break;
  }
  return state;
}

void keyboard_post_init_user(void) {
  // Set default led colours.
  rgblight_enable_noeeprom(); // enables RGB, without saving settings
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 2); // sets mode to Fast breathing without saving
  layer_state_set_user(0);
}

/* Local Variables: */
/* compile-command: "cd ../../../../.. && (test -f lib/lufa/LUFA/makefile || make git-submodule) && make keebio/iris/rev3:sanityinc:dfu" */
/* End: */
