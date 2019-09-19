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

// Hack for blanks
#define KC_ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT_kc(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      GRV    ,   1    ,   2    ,   3    ,   4    ,   5    ,                              6    ,   7    ,   8    ,   9    ,   0    ,  BSPC  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     TAB_NUM ,   Q    ,   W    ,   E    ,   R    ,   T    ,                              Y    ,   U    ,   I    ,   O    ,   P    ,  BSLS  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      LCTL   ,   A    ,   S    ,   D    ,   F    ,   G    ,                              H    ,   J    ,   K    ,   L    ,  SCLN  ,  QUOT  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      LSFT   ,   Z    ,   X    ,   C    ,   V    ,   B    , LBRC   ,          RBRC   ,   N    ,   M    , COMM   ,  DOT   ,  SLSH  ,SFT_ENT ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     LALT   ,  LWR   ,  LGUI  ,                  CTL_SPC ,RAI_MIN ,LCAG_EQL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

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
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 1); // sets mode to Fast breathing without saving
  layer_state_set_user(0);
}

/* Local Variables: */
/* compile-command: "cd ../../../../.. && (test -f lib/lufa/LUFA/makefile || make git-submodule) && make keebio/iris/rev3:sanityinc:dfu" */
/* End: */
