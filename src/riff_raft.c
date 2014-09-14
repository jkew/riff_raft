#include <stdlib.h>
#include <include/riff_raft.h>

state *current;

void init_state() {
  current = malloc(sizeof(state));
  current->role = CANDIDATE;
}

void next_state() {
  switch(current->role) {
  case CANDIDATE:
    break;
  case FOLLOWER:
    break;
  case LEADER:
    break;
  }

}
