#pragma once

#include <stdint.h>
#include "../../config/config.h"
#include "../../../state/state.h"

#define MAX_TITLE_LENGTH 256
#define MAX_DESC_LENGTH  2028
#define MAX_NAME_LENGTH  256
#define MAX_FORM_LENGTH  256

typedef struct {
  char experimentName[MAX_NAME_LENGTH];
  char experimentDesc[MAX_DESC_LENGTH];
  char experimentTitle[MAX_TITLE_LENGTH];

  char userName[MAX_NAME_LENGTH];

  uint16_t experimentDuration_hours;
  uint16_t experimentDuration_minutes;
  uint16_t experimentDuration_seconds;
  uint16_t experimentDelay_minutes;
  uint8_t  experimentSlot;
} ExperimentForm;

void clearExperimentForm(ExperimentForm* form);

TimeConfig getTimeConfig(ExperimentForm* form);

ExperimentConfig getExperimentConfig(ExperimentForm* form);

SessionConfig getSessionConfig(ExperimentForm* form);

ExperimentSession getExperimentSessionConfig(ExperimentForm* form);

ExperimentSession* allocateExperimentSessionConfig(ExperimentForm* form);


// STATEFUL COMPONENT
// This component captures the user input from the form

void experimentFormView(AppContext* ctx);
