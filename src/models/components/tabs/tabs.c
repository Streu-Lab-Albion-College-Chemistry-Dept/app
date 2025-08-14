#include "./tabs.h"
#include <clay/clay.h>

void ContextTabs(AppContext* ctx) {
  CLAY({
    .backgroundColor = {123, 23, 156, 79},
    .layout = {
      .childGap = 16,
      .layoutDirection = CLAY_LEFT_TO_RIGHT,
      .padding = {16, 16, 16, 16},
      .sizing = {
        .width = CLAY_SIZING_GROW(0),
        .height = CLAY_SIZING_GROW(0)
      }
    },
    .cornerRadius = {
      .topLeft = 8,
      .topRight = 8,
      .bottomLeft = 8,
      .bottomRight = 8,
    }
  }) {
    for (int i = 0; i < ctx->APP_SESSION_total_experiments; ++i) {
      CLAY({
        .backgroundColor = {255, 255, 255, 255},
        .cornerRadius = CLAY_CORNER_RADIUS(8),
        .layout = {
          .sizing = {
            .width = CLAY_SIZING_FIT(60),
            .height = CLAY_SIZING_FIT(60),
          },
          .padding = {10, 10, 10, 10}
        }
      });
    }
  }
}


void DemoView(AppContext* ctx) {
  CLAY({
    .backgroundColor = {255, 255, 255, 255},
    .layout = {
      .childGap = 16,
      .layoutDirection = CLAY_LEFT_TO_RIGHT,
      .padding = {16, 16, 16, 16},
      .sizing = {
        .width = CLAY_SIZING_GROW(0),
        .height = CLAY_SIZING_GROW(0)
      }
    },
    .cornerRadius = {
      .topLeft = 8,
      .topRight = 8,
      .bottomLeft = 8,
      .bottomRight = 8,
    }
  }) {
    for (int i = 0; i < ctx->APP_SESSION_total_experiments; ++i) {
      CLAY({
        .backgroundColor = {255, 255, 255, 255},
        .cornerRadius = CLAY_CORNER_RADIUS(8),
        .layout = {
          .sizing = {
            .width = CLAY_SIZING_FIT(60),
            .height = CLAY_SIZING_FIT(60),
          },
          .padding = {10, 10, 10, 10}
        }
      });
    }
  }
}

void HandleTabClick(
  Clay_ElementId id,
  Clay_PointerData pointerData,
  intptr_t userData
) {
  if (pointerData.state == CLAY_POINTER_DATA_PRESSED_THIS_FRAME) {
    TabPropsArray* tabs = (TabPropsArray*)userData;
    if (userData >= 0 && userData < tabs->length) {
      tabs->selectedIndex = userData;
    }
  }
}
