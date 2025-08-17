#include <clay/clay.h>
#include "./profiles.h"

void UserProfileWidget(AppContext* ctx) {
  CLAY({
    .layout = {
      .layoutDirection = CLAY_TOP_TO_BOTTOM,
      .childGap = 8,
      .sizing = {
        .width = CLAY_SIZING_GROW(0),
        .height = CLAY_SIZING_GROW(0),
      }
    }
  }) {
    
    CLAY({
      .layout = {
        .layoutDirection = CLAY_LEFT_TO_RIGHT,
        .childGap = 8,
        .sizing = {.width = CLAY_SIZING_GROW(0),}
      }
    }) {

      CLAY({
        .backgroundColor = {255, 255, 255, 150},
        .cornerRadius = CLAY_CORNER_RADIUS(4),
        .layout = {
          .sizing = {
            .width = CLAY_SIZING_FIXED(80),
            .height = CLAY_SIZING_FIXED(80),
          }
        }
      }) {} 

      CLAY_TEXT(CLAY_STRING("DEMO VIEW"), CLAY_TEXT_CONFIG({
        .fontSize = 16,
        .textColor = {255, 255, 255, 200}
      }));

    }
    
    CLAY({
      .backgroundColor = {255, 255, 255, 100},
      .cornerRadius = CLAY_CORNER_RADIUS(4),
      .layout = {
        .sizing = {
          .width =  CLAY_SIZING_GROW(0),
          .height = CLAY_SIZING_GROW(0)
        }
      }
    }) {}

  }
}
