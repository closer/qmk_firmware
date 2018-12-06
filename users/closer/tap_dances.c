#include "closer.h"
#include "tap_dances.h"

#include "quantum.h"
#include "action.h"
#include "process_keycode/process_tap_dance.h"

void qk_tap_dance_triple_on_each_tap (qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_triple_t *triple = (qk_tap_dance_triple_t *)user_data;

  if (state->count == 3) {
    register_code16 (triple->kc3);
    state->finished = true;
  }
}

void qk_tap_dance_triple_finished (qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_triple_t *triple = (qk_tap_dance_triple_t *)user_data;

  if (state->count == 1) {
    register_code16 (triple->kc1);
  } else if (state->count == 2) {
    register_code16 (triple->kc2);
  } else if (state->count == 3) {
    register_code16 (triple->kc3);
  }
}

void qk_tap_dance_triple_reset (qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_triple_t *triple = (qk_tap_dance_triple_t *)user_data;

  if (state->count == 1) {
    unregister_code16 (triple->kc1);
  } else if (state->count == 2) {
    unregister_code16 (triple->kc2);
  } else if (state->count == 3) {
    unregister_code16 (triple->kc3);
  }
}

void qk_tap_dance_mod_pair_on_each_tap (qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_triple_t *triple = (qk_tap_dance_triple_t *)user_data;

  if (state->count == 2) {
    unregister_code16 (triple->kc1);
    register_code16 (triple->kc3);
    state->finished = true;
    return;
  }

  register_code16 (triple->kc1);
}

void qk_tap_dance_mod_pair_finished (qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_triple_t *triple = (qk_tap_dance_triple_t *)user_data;

  if (!state->pressed) {
    unregister_code16 (triple->kc1);
    if (state->count == 1) {
      register_code16 (triple->kc2);
    } else if (state->count == 2) {
      register_code16 (triple->kc3);
    }
  }
}

void qk_tap_dance_mod_pair_reset (qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_triple_t *triple = (qk_tap_dance_triple_t *)user_data;

  unregister_code16 (triple->kc1);

  if (state->count == 1) {
    unregister_code16 (triple->kc2);
  } else if (state->count == 2) {
    unregister_code16 (triple->kc3);
  }
}
