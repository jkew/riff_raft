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
  REPLY_FALSE,
  REPLY_TRUE,
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
  list_ref *next_index;
  list_ref *match_index;
  long current_term;
  int voted_for;
  list_ref *log;
} node_state;

typedef struct {
  enum command_type cmd_type;
  long msg_id;
  long term;
  int from;
  int to;
  char *data;
} message;

void reply_false(message *msg, node_state *current);
void reply_true(message *msg, node_state *current);
void forward_message(int leader, message *msg);
void init_state();
void next_state(message *msg);

#endif
