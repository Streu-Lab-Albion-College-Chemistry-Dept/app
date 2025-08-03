#include "raylib.h"
#include "./components.h"

/*
 * Top Menu Bar
*/
void RenderHeaderButton(Clay_String text, AppContext* ctx) {
  CLAY({
    .layout = {.padding = {16, 8}},
    .backgroundColor = {},
    .cornerRadius = {12, 12, 12, 12},
    .backgroundColor = {140, 140, 140, 255},
  }) {
    CLAY_TEXT(text, CLAY_TEXT_CONFIG({
      .fontSize = 16,
      .textColor = {255, 255, 255, 255},
    }));
  }
}

void RenderHeaderDropdownButton(Clay_String text, AppContext* ctx) {
  CLAY({
    .layout = {.padding = {16, 8}},
    .cornerRadius = {5, 5, 5, 5},
    .backgroundColor = {140, 140, 140, 255},
  }) {
    CLAY_TEXT(text, CLAY_TEXT_CONFIG({
      .fontSize = 16,
      .textColor = {255, 255, 255, 255},
    }));
  }
}

void SideBar(AppContext* ctx) {
  Clay_Sizing expandLayout = {
    .height = CLAY_SIZING_GROW(),
    .width  = CLAY_SIZING_GROW(),
  }
  
  CLAY({ 
    .id = CLAY_ID("SideBar"),
    .layout = {
      .layoutDirection = CLAY_TOP_TO_BOTTOM,
      .childGap        = 16,
      .padding         = {4, 4, 4, 4},
      .sizing = {
        .width  = CLAY_SIZING_FIXED(250),
        .height = CLAY_SIZING_GROW();
      }
    },
    .backgroundColor = APP_COLOR_sideBar,
    .cornerRadius = {12, 12, 12, 12},
  }) {
    CLAY({
      .id = CLAY_ID("title-bar"),
      .layout = {
        .sizing = {
          .height = CLAY_SIZING_FIXED(60),
          .width  = CLAY_SIZING_FIXED(),
        }
      },
    }) {};
    
    CLAY({
      .id = CLAY_ID("exp-configs"),
      .layout = {
        .sizing = expandLayout,
      } 
    }) {}
  };
}

void TopMenuBar(AppContext* ctx) {
  CLAY({
    .backgroundColor = APP_COLOR_sideBar,
    .cornerRadius = {12, 12, 12, 12},
    .id = CLAY_ID("top-menu-bar"),
    .layout = {
      .layoutDirection = CLAY_LEFT_TO_RIGHT,
      .padding = {4, 4, 4, 4},
      .sizing = {
        .height = CLAY_SIZING_FIXED(60),
        .width  = CLAY_SIZING_GROW(),
      },
      .childGap = 16,
      .childAlignment = {.y = CLAY_ALIGN_Y_CENTER},
    }
  }) {
    CLAY({
      .id = CLAY_ID("file-button"),
      .layout = {.padding = {16, 8},},
      .backgroundColor = {140, 140, 140, 255},
      .cornerRadius = {4, 4, 4, 4},
    }) {
      CLAY_TEXT(CLAY_STRING("File"), CLAY_TEXT_CONFIG({
          .fontSize = 16,
          .textColor = {255, 255, 255, 255},
      }));

      CLAY({
        .id = CLAY_ID("file-button"),
        .floating = {},
        .backgroundColor = {40, 40, 40, 255},
        .layout = {
          .layoutDirection = CLAY_TOP_TO_BOTTOM,
          .sizing = {.width = CLAY_SIZING_FIXED(200)} 
        }
      }) {
        RenderHeaderDropdownButton(CLAY_STRING("New"), ctx);
        RenderHeaderDropdownButton(CLAY_STRING("Open"), ctx);
        RenderHeaderDropdownButton(CLAY_STRING("Save"), ctx);
        RenderHeaderDropdownButton(CLAY_STRING("Close"), ctx);
      }
    }
    RenderHeaderButton(CLAY_STRING("File"), ctx);
    RenderHeaderButton(CLAY_STRING("Edit"), ctx);
    CLAY({.layout = {.sizing = {.width = CLAY_SIZING_GROW()}}});
    RenderHeaderButton(CLAY_STRING("Settings"), ctx);
  }
}
