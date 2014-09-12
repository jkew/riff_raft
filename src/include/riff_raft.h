#ifndef RIFFRAFT
#define RIFFRAFT


enum command_type {
  APPEND,
  ELECTION,
  HEARTBEAT,
  GET,
  SET,
  UNKNOWN
};

typedef struct {
  enum command_type command;
  long term;
} log_entry;

typedef struct {
  long current_term;
  int voted_for;  
} persistent_state;

typedef struct {
  long commit_index;
  int last_applied;
  long *next_index;
  long *match_index;
} state;


typedef struct {
  enum command_type type;
  long term;
} message;
#endif
