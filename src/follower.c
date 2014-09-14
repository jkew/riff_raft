#include <stdio.h>
#include "include/riff_raft.h"
#include "include/common.h"
#include "include/follower.h"

void follower_next_state(state *current, message *msg) {
  common_next_state(current, msg);
  handle_append_entry(current, msg);
  handle_request_vote(current, msg);
  // if election timeout has expired
  //   send request_vote_rpc to all nodes

}

