#pragma once
#include <clay/clay.h>
#include "../../../state/state.h"

void ContextTabs(AppContext* ctx);
void DemoView(AppContext* ctx);

// callback handler
void HandleTabClick(
  Clay_ElementId id,
  Clay_PointerData pointerData,
  intptr_t userData
);

// tab props
typedef struct {
  Clay_String title;
  void (*contentView)(AppContext*);
} TabProps;

typedef struct {
  TabProps* props;
  uint16_t length;
  uint16_t selectedIndex;
} TabPropsArray;
