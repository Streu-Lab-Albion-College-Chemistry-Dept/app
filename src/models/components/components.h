#pragma once
#include "../../state/state.h"
#include "../../../include/clay/clay.h"

static const Clay_Color APP_COLOR_LIGHT     __attribute__((unused)) = {225, 220, 222, 255};
static const Clay_Color APP_COLOR_DARK      __attribute__((unused)) = {25, 100, 106, 255};
static const Clay_Color APP_COLOR_sideBar   __attribute__((unused)) = {255, 248, 240, 255};
static const Clay_Color APP_COLOR_buttonRun __attribute__((unused)) = {35, 12, 51, 255};

void SideBar(AppContext* ctx);
void TopMenuBar(AppContext* ctx);
void MainContent(AppContext* ctx);
void RenderHeaderButton(Clay_String text, AppContext* ctx);
void RenderHeaderDropdownButton(Clay_String text, AppContext* ctx);
void ExpConfig(AppContext* ctx);
void RelayMods(AppContext* ctx);
void LogDisplDesc(AppContext* ctx);
void LogDispl(AppContext* ctx);
void ExperimentVisualContainer(AppContext* ctx);
