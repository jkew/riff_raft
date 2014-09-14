#ifndef RIFFRAFT
#define RIFFRAFT
#include "list.h"

enum role_type {
  FOLLOWER,
  CANDIDATE,
  LEADER
};

enum command_type {
  APPEND,
  ELECTION,
  HEARTBEAT,
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
  list_ref *next_index;
  list_ref *match_index;
  long current_term;
  int voted_for;
  list_ref *log;
} state;

typedef struct {
  enum command_type type;
  long term;
  int from;
  int to;
  char *data;
} message;

void init_state();
void next_states();

#endif
