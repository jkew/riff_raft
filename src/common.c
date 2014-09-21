#include <stdio.h>
#include "include/riff_raft.h"
#include "include/common.h"
#include "include/util.h"
#include "include/list.h"

node_state * handle_term_check(node_state *current, message *msg);

node_state * common_next_state(node_state *current, message *msg) {
  //If commitIndex > lastApplied: increment lastApplied, apply
  //  log[lastApplied] to state machine
  //If RPC request or response contains term T > currentTerm:
  //  set currentTerm = T, convert to follower

}

node_state * handle_append_entry(node_state *current, message *msg) {
  //TODO: Q. Do only followers handle this one?


  // 1. Reply false if term < currentTerm (§5.1)
  if (!handle_term_check(current, msg)) {
    // We are receiving messages from an old leader?
    return DONE;
  }
  // 2. Reply false if log doesn’t contain an entry at prevLogIndex
  //    whose term matches prevLogTerm (§5.3) and do not append the new entries
  append_entries_args * args = ((append_entries_args *) msg->args);
  log_entry * curr_entry = list_get(current->log, args->prev_log_index );
  if (curr_entry == NULL || curr_entry->term != args->prev_log_term) {
    // Our log is out of sync with the current leader; we do not have the
    // intermediate log entries.
    //TODO:  Q. How do we resync the log?
    reply_false(msg, current);
    return DONE;
  }
  // 3. If an existing entry conflicts with a new one (same index
  //    but different terms), delete the existing entry and all that
  //    follow it (§5.3)

  //TODO: Q. Which index is associated with the new entry?
  log_entry new_entry = args->entry;
  int current_index = args->prev_log_index + 1;
  // 4. Append any new entries not already in the log
  // 5. If leaderCommit > commitIndex, set commitIndex =
  //    min(leaderCommit, index of last new entry)
}

node_state * handle_request_vote(node_state *current, message *msg) {
  //TODO: NOOP if this is the wrong message
  // 1. Reply false if term < currentTerm (§5.1)
  if (!handle_term_check(current, msg)) { return current; }
  // 2. If votedFor is null or candidateId, and candidate’s log is at
  //    least as up-to-date as receiver’s log, grant vote (§5.2, §5.4)
}


node_state * handle_term_check(node_state *current, message *msg) {
  // 1. Reply false if term < currentTerm (§5.1)
  if ( (msg->term) < (current->current_term)) {
    reply_false(msg, current);
    return DONE;
  }
  return current;
}

