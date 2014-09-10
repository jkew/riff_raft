#ifndef RIFFRAFT
#define RIFFRAFT
enum message_type {
  VOTE,
  ELECTION,
  HEARTBEAT,
  UNKNOWN
};

typedef struct {
  enum message_type type;
  long term;
} message;
#endif
