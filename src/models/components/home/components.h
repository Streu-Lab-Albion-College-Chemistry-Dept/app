#pragma once
#include "../../../state/state.h"
#include <clay/clay.h>

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

// Non contextual components
void Tabs(Clay_String title);
