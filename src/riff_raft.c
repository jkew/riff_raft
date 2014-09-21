#include <stdlib.h>
#include <include/riff_raft.h>

node_state *current;

void init_state() {
  current = malloc(sizeof(node_state));
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
