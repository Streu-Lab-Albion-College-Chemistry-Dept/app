#include "config.h"
#include <time.h>

TimeConfig createTimeConfig(
  uint16_t hours,
  uint16_t minutes,
  uint16_t seconds,
  uint16_t delay
) {
  return (TimeConfig) {
    .exp_hours   = hours,
    .exp_minutes = minutes,
    .exp_seconds = seconds,
    .exp_delay   = delay,
  };
}

DateConfig createDateConfig() {
  time_t now = time(NULL);
  struct tm* t = localtime(&now);

  return (DateConfig) {
    .year  = t->tm_year + 1900,
    .month = t->tm_mon + 1,
    .day   = t->tm_mday,
  };
}

ExperimentConfig createExperimentConfig(uint8_t slot, TimeConfig* time) {
  return (ExperimentConfig) {
    .tconf = time,
    .exp_slot = slot,
  };
}

SessionConfig createSessionConfig(
  const char* username,
  DateConfig* dateconfig,
  ExperimentConfig* experiment
 ) {
  return (SessionConfig) {
    .user =  username,
    .date = dateconfig,
    .config = experiment,
  };
}
