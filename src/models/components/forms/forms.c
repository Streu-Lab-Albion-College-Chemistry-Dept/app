#include <stdlib.h>
#include <string.h>
#include <raylib.h>
#include <clay/clay.h>
#include "../../../state/state.h"
#include "./forms.h"
#include "../../config/config.h"


static ExperimentForm experimentForm = (ExperimentForm) {
  .experimentName             = "",
  .experimentDesc             = "",
  .experimentTitle            = "",
  .userName                   = "",
  .experimentDuration_hours   = 0,
  .experimentDuration_minutes = 0,
  .experimentDuration_seconds = 0,
  .experimentDelay_minutes    = 0,
  .experimentSlot             = 0,
};

void clearExperimentForm(ExperimentForm* form) {
  memset(form, 0, sizeof(ExperimentForm));
}

TimeConfig getTimeConfig(ExperimentForm* form) {
  return (TimeConfig) {
    .exp_hours   = form->experimentDuration_hours,
    .exp_minutes = form->experimentDuration_minutes,
    .exp_seconds = form->experimentDuration_seconds,
    .exp_delay   = form->experimentDelay_minutes,
  };
}

ExperimentConfig getExperimentConfig(ExperimentForm* form) {
  TimeConfig config   = getTimeConfig(form);
  TimeConfig* timeconf = (TimeConfig*)malloc(sizeof(TimeConfig));
  
  memcpy(timeconf, &config, sizeof(TimeConfig));

  return (ExperimentConfig) {
    .tconf    = timeconf,
    .exp_slot = form->experimentSlot,
  };
}

SessionConfig getSessionConfig(ExperimentForm* form) {
  DateConfig date = createDateConfig();
  DateConfig* dateconf = (DateConfig*)malloc(sizeof(DateConfig));

  ExperimentConfig exp = getExperimentConfig(form);
  ExperimentConfig* expconf = (ExperimentConfig*)malloc(sizeof(ExperimentConfig));

  memcpy(dateconf, &date, sizeof(DateConfig));
  memcpy(expconf, &exp, sizeof(ExperimentConfig));
  
  return (SessionConfig) {
    .user   = form->userName,
    .date   = dateconf,
    .config = expconf,
  };
}


ExperimentSession getExperimentSessionConfig(ExperimentForm* form) {
  SessionConfig session = getSessionConfig(form);
  SessionConfig* sessionconf = (SessionConfig*)malloc(sizeof(SessionConfig));

  memcpy(sessionconf, &session, sizeof(SessionConfig));

  return (ExperimentSession) {
    .config    = sessionconf,
    .is_active = false,
  };
}

ExperimentSession* allocateExperimentSessionConfig(ExperimentForm* form) {
  ExperimentSession session = getExperimentSessionConfig(form);
  ExperimentSession* sessionconf = (ExperimentSession*)malloc(sizeof(ExperimentSession));
  
  memcpy(sessionconf, &session, sizeof(ExperimentSession));

  return sessionconf;
}

// STATEFUL FORM COMPONENT
// This component captures the user input and adds it as a form


void experimentFormView(AppContext* ctx) {
  int screenWidth = GetScreenWidth();
  int screenHeight = GetScreenHeight();

  int rectWidth = 300;
  int rectHeight = 200;

  // Calculate top-left position to center the rectangle
  int rectX = (screenWidth - rectWidth) / 2;
  int rectY = (screenHeight - rectHeight) / 2;


  BeginDrawing();
  DrawRectangle(rectX, rectY, rectWidth, rectHeight, (Color){ 100, 100, 100, 255 });
  EndDrawing();
}
