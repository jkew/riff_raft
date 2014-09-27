#ifndef RIFFRAFT
#define RIFFRAFT
#include "list.h"
#include "util.h"

enum role_type {
  FOLLOWER,
  CANDIDATE,
  LEADER
};

enum command_type {
  APPEND,
  ELECTION,
  HEARTBEAT,
  REPLY,
  GET,
  SET
};

typedef struct {
  enum command_type command;
  long term;
} log_entry;

typedef struct {
  enum role_type role;
  long commit_index;
  int last_applied;
  int myid;
  long current_term;
  int voted_for;
  list_ref *next_index;
  list_ref *match_index;
  list_ref *log;
} node_state;

typedef struct {
  enum command_type cmd_type;
  long msg_id;
  long term;
  int from;
  int to;
  void *args;
} message;

typedef struct {
  int leader_id;
  int prev_log_index;
  int prev_log_term;
  log_entry entry; // may send more than one for efficiency
  int leader_commit_index;
} append_entries_args;

typedef struct {
  int candidate_id;
  int last_log_index;
  int last_log_term;
} request_vote_args;

typedef struct {
  bool success;
} message_reply;


void reply_false(message *msg, node_state *current);
void reply_true(message *msg, node_state *current);
void forward_message(int leader, message *msg);
void init_state();
void next_state(message *msg);
node_state * new_state();
void discard_state(node_state * state);
bool state_equals(node_state * r, node_state *l);

#endif
