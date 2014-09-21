#ifndef RRFOLLOWER
#define RRFOLLOWER
#include "riff_raft.h"

node_state * common_next_state(node_state *current, message *msg);
node_state *  handle_append_entry(node_state *current, message *msg);
node_state *  handle_request_vote(node_state *current, message *msg);

#endif
