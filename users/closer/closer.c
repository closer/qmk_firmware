#include "closer.h"
#include "tap_dances.h"

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_GUIH] = ACTION_TAP_DANCE_MOD_DOUBLE(KC_LGUI, KC_HANJ, KC_HAEN),
  [SPCCMDT] = ACTION_TAP_DANCE_TRIPLE(KC_SPC, KC_COMM, KC_DOT)
};
