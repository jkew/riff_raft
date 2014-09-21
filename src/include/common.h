#ifndef RRFOLLOWER
#define RRFOLLOWER
#include "riff_raft.h"

void common_next_state(node_state *current, message *msg);
void handle_append_entry(node_state *current, message *msg);
void handle_request_vote(node_state *current, message *msg);

#endif
