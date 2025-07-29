#include "config.h"

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

DateConfig createDateConfig(
  uint16_t year,
  uint8_t  month,
  uint8_t  day
  ) {
  return (DateConfig) {
    .year  = year,
    .month = month,
    .day   = day,
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
