#include <stdlib.h>
#include <include/riff_raft.h>

state *current;

void init_state() {
  current = malloc(sizeof(state));
  current->role = CANDIDATE;
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
