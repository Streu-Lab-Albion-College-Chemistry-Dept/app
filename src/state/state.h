#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../models/config/config.h"
#include "../../include/queue/queue.h"

#define MAX_EXPERIMENTS 8

typedef struct {
  bool               APP_SESSION_alive;
  bool               APP_SESSION_active;
  uint8_t            APP_SESSION_total_experiments;
  uint8_t*           APP_SESSION_active_exp;
  char*              APP_SESSION_current_user;
  ExperimentSession* APP_SESSION_current_exp_session;
  MetaData*          APP_SESSION_metadata; 
  Queue              APP_SESSION_exp_logs_queue;
  FILE*              APP_SESSION_logFile;
} AppContext;

static inline AppContext StartApplication() {
  return (AppContext) {
    .APP_SESSION_alive               = true,
    .APP_SESSION_active              = false,
    .APP_SESSION_total_experiments   = MAX_EXPERIMENTS,
    .APP_SESSION_active_exp          = NULL,
    .APP_SESSION_current_user        = NULL,
    .APP_SESSION_current_exp_session = NULL,
    .APP_SESSION_metadata            = NULL,
    .APP_SESSION_exp_logs_queue      = new_queue(),
    .APP_SESSION_logFile             = NULL,
  };
}
