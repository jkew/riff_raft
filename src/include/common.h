#ifndef RRFOLLOWER
#define RRFOLLOWER
#include "riff_raft.h"

void common_next_state(state *current, message *msg);
void handle_append_entry(state *current, message *msg);
void handle_request_vote(state *current, message *msg);

#endif
