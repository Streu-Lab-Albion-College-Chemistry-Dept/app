#define CLAY_IMPLEMENTATION
#include "../../state/state.h"
#include "../../../include/clay/clay.h"

const Clay_Color APP_COLOR_LIGHT = (Clay_Color) {225, 220, 222, 1};
const Clay_Color APP_COLOR_DARK  = (Clay_Color) {25, 100, 106, 1};
const Clay_Color APP_COLOR_sideBar = (Clay_Color) {255, 248, 240, 1};
const Clay_Color APP_COLOR_buttonRun = (Clay_Color) {35, 12, 51, 1};

void SideBar(AppContext* ctx);
void TopMenuBar(AppContext* ctx);
void RenderHeaderButton(Clay_String text, AppContext* ctx);
void RenderHeaderDropdownButton(Clay_String text, AppContext* ctx);
void ExpConfig(AppContext* ctx);
void RelayMods(AppContext* ctx);
void LogDisplDesc(AppContext* ctx);
void LogDispl(AppContext* ctx);

