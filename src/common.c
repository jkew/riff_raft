#include <stdio.h>
#include "include/riff_raft.h"
#include "include/common.h"

state * common_next_state(state *current, message *msg) {
  //If commitIndex > lastApplied: increment lastApplied, apply
  //  log[lastApplied] to state machine
  //If RPC request or response contains term T > currentTerm:
  //  set currentTerm = T, convert to follower
}

state * handle_append_entry(state *current, message *msg) {
  // 1. Reply false if term < currentTerm (§5.1)
  // 2. Reply false if log doesn’t contain an entry at prevLogIndex
  //    whose term matches prevLogTerm (§5.3)
  // 3. If an existing entry conflicts with a new one (same index
  //    but different terms), delete the existing entry and all that
  //    follow it (§5.3)
  // 4. Append any new entries not already in the log
  // 5. If leaderCommit > commitIndex, set commitIndex =
  //    min(leaderCommit, index of last new entry)
}

state * handle_request_vote(state *current, message *msg) {
  // 1. Reply false if term < currentTerm (§5.1)
  // 2. If votedFor is null or candidateId, and candidate’s log is at
  //    least as up-to-date as receiver’s log, grant vote (§5.2, §5.4)
}
