#include <stdio.h>
#include "include/riff_raft.h"
#include "include/follower.h"

void recv(message msg) {
  println("Got Message %d", msg.type);
}
