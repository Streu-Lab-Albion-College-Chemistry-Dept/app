#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef struct {
  uint16_t exp_hours;
  uint16_t exp_minutes;
  uint16_t exp_seconds;
  uint16_t exp_delay;
} TimeConfig;

typedef struct {
  TimeConfig* tconf;
  uint8_t  exp_slot;  
} ExperimentConfig;

typedef struct {
  uint16_t year;
  uint8_t  month;
  uint8_t  day;
} DateConfig;

typedef struct {
  const char*       user;
  DateConfig*       date;
  ExperimentConfig* config;
} SessionConfig;

typedef struct {
  ExperimentConfig MTD_exp;
  DateConfig       MTD_date; 
} MetaData;

typedef struct {
  SessionConfig* config;
  bool           is_active;
} ExperimentSession;

TimeConfig createTimeConfig(uint16_t hours, 
                            uint16_t minutes,
                            uint16_t seconds,
                            uint16_t delay);

DateConfig createDateConfig(uint16_t year,
                            uint8_t  month,
                            uint8_t  day);

ExperimentConfig createExperimentConfig(uint8_t slot, TimeConfig* time);

SessionConfig createSessionConfig(const char* username,
                                  DateConfig* dateconfig,
                                  ExperimentConfig* experiment);

