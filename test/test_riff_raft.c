#include <../src/include/riff_raft.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_new_state() {
  node_state *test_state = new_state();
  assert(test_state->role == CANDIDATE);
  assert(test_state->myid == -1);
  assert(test_state->current_term == -1);
  assert(test_state->voted_for == -1);
  assert(test_state->commit_index == -1);
  assert(test_state->last_applied == -1);
  assert(test_state->match_index != NULL);
  assert(test_state->next_index != NULL);
  assert(test_state->log != NULL);
  discard_state(test_state);
}

void print_state_bytes(node_state *s) {
  printf("[");
  for (int i = 0; i < sizeof(node_state); i++) { printf("%02x ", ((const unsigned char *) s)[i]); }
  printf("]\n");
}

void test_state_equals() {
  node_state *r_state = new_state();
  node_state *l_state = new_state();
  print_state_bytes(r_state);
  print_state_bytes(l_state);
  assert(state_equals(r_state,l_state));
  r_state->myid = 1;
  assert(!state_equals(r_state,l_state));
  // test log change
  discard_state(r_state);
  discard_state(l_state);
}

void main() {
  test_new_state();
  test_state_equals();
}
