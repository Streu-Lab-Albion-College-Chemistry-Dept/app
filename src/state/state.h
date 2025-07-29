#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../models/config/config.h"
#include "../../include/queue/queue.h"

typedef struct {
  bool               APP_SESSION_alive;
  bool               APP_SESSION_active;
  uint8_t            APP_SESSION_active_exp;
  char*              APP_SESSION_current_user;
  ExperimentSession* APP_SESSION_current_exp_session;
  MetaData*          APP_SESSION_metadata; 
  Queue              APP_SESSION_exp_logs_queue;
  FILE*              APP_SESSION_logFile;
} AppContext;
