#include "./tabs.h"
#include "../forms/forms.h"
#include <clay/clay.h>
#include <raylib.h>

#define MAX_WIDTH 1500

void ContextTabs(AppContext* ctx) {
  float width = GetScreenWidth();
  CLAY({
    .layout = {
      .layoutDirection = CLAY_LEFT_TO_RIGHT,
      .childGap = 16,
      .sizing = {
        .width = CLAY_SIZING_GROW(0),
        .height = CLAY_SIZING_GROW(0)
      }
    }
  }) {
    CLAY({
      .backgroundColor = {255, 255, 255, 100},
      .layout = {
        .childGap = 8,
        .layoutDirection = width < MAX_WIDTH 
          ? CLAY_TOP_TO_BOTTOM 
          : CLAY_LEFT_TO_RIGHT,
        .padding = CLAY_PADDING_ALL(8),
        .sizing = {
          .height = CLAY_SIZING_GROW(0),
          .width = CLAY_SIZING_PERCENT(0.5)
        }
      },
      .cornerRadius = CLAY_CORNER_RADIUS(8),
      .clip = {
        .vertical = true,
        .horizontal = true,
        .childOffset = Clay_GetScrollOffset(),
      }
    }) {

      
      for (uint8_t i = 0; i < ctx->APP_SESSION_total_experiments; ++i) {
        CLAY({
          .id = CLAY_IDI("exp-boxes", i),
          .backgroundColor = {255, 255, 255, 255},
          .cornerRadius = CLAY_CORNER_RADIUS(8),
          .layout = {
            .sizing = {
              .width = width < MAX_WIDTH 
                ? CLAY_SIZING_PERCENT(0.2) 
                : CLAY_SIZING_GROW(0.5),
              .height = CLAY_SIZING_PERCENT(0.15),
            },
            .padding = {10, 10, 10, 10}
          }
        });

        if (Clay_PointerOver(CLAY_IDI("exp-boxes", i))) {
          printf("Hovering over index %i\n", i);
          experimentFormView(ctx);
        }
      }

    }

    CLAY({
      .layout = {
        .layoutDirection = CLAY_TOP_TO_BOTTOM,
        .childGap = 8,
        .padding = CLAY_PADDING_ALL(8),
        .sizing = {
          .width = CLAY_SIZING_GROW(0),
          .height = CLAY_SIZING_GROW(0)
        },
      },
      .backgroundColor = {255, 255, 255, 100},
      .cornerRadius = CLAY_CORNER_RADIUS(8),
    }) {

      CLAY({
        .backgroundColor = {255, 255, 255, 100},
        .layout = {
          .layoutDirection = CLAY_LEFT_TO_RIGHT,
          .padding = CLAY_PADDING_ALL(4),
          .sizing = {.width = CLAY_SIZING_GROW(0)}
        },
        .cornerRadius = CLAY_CORNER_RADIUS(4)
      }) {
        CLAY_TEXT(CLAY_STRING("Schema"), CLAY_TEXT_CONFIG({
          .fontSize = 16,
          .textColor = {0, 0, 0, 200},
        }));
      }

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
  TabsInterface* tabs = (TabsInterface*)userData;
  if (pointerData.state == CLAY_POINTER_DATA_PRESSED_THIS_FRAME) {
    printf("Clicked tab %d\n", (int)tabs->tabsList->selectedIndex);
    if (tabs->currentIndex >= 0 && tabs->currentIndex < tabs->tabsList->length) {
      tabs->tabsList->selectedIndex = tabs->currentIndex;
    }
  }
}
