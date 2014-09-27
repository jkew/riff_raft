#include <stdlib.h>
#include <include/riff_raft.h>

node_state *current;

node_state * new_state() {
  node_state *state = malloc(sizeof(node_state));
  state->role = CANDIDATE;
  state->commit_index = -1;
  state->last_applied = -1;
  state->myid = -1;
  state->current_term = -1;
  state->voted_for = -1;
  state->match_index = new_list();
  state->next_index = new_list();
  state->log = new_list();
  return state;
}

void discard_state(node_state *state) {
  void *entry = NULL;
  while((entry = popv(state->match_index)) != NULL) {
    discard(entry);
  }
  discard(state->match_index);
  while((entry = popv(state->next_index)) != NULL) {
    discard(entry);
  }
  discard(state->next_index);
  while((entry = popv(state->log)) != NULL) {
    discard(entry);
  }
  discard(state->log);
  discard(state);
}

bool state_equals(node_state *r, node_state *l) {
  if (memcmp(r,l, sizeof(node_state) - (sizeof(void *) * 3)) != 0) {
    return FALSE;
  }
  //TODO: Log compare
  return TRUE;
  
}

void init_state() {
  current = new_state();
}

void next_state(message *msg) {
  current = common_next_state(current, msg);
  switch(current->role) {
  case CANDIDATE:
    break;
  case FOLLOWER:
    current = follower_next_state(current, msg);
    break;
  case LEADER:
    break;
  }
}
