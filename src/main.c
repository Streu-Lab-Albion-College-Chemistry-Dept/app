#include <stdlib.h>
#include <stdint.h>
#include "raylib.h"
#include "../include/clay/clay.h"
#include "./models/components/components.h"
#include "../include/renderer/clay_renderer_raylib.h"

void ErrorHandler(Clay_ErrorData error) {}

int main() {
  AppContext context = StartApplication();

  uint64_t totalMemorySize = Clay_MinMemorySize();
  Font defaultFont = LoadFont("");
  Clay_Arena arena = Clay_CreateArenaWithCapacityAndMemory(
    totalMemorySize, 
    malloc(totalMemorySize)
  );

  Clay_Initialize(
    arena, 
    (Clay_Dimensions) {
      .width = GetScreenWidth(),
      .height = GetScreenHeight(),
    }, 
    (Clay_ErrorHandler) {ErrorHandler}
  );

  InitWindow(800, 450, "this is a test");

  while (!WindowShouldClose()) {
    Clay_BeginLayout();
    CLAY({
      .backgroundColor = {},
      .layout = {
        .sizing = {
          .width = CLAY_SIZING_GROW(),
          .height = CLAY_SIZING_GROW(),
        }
      }

    }) {
      TopMenuBar(&context);
      SideBar(&context);
    }
    Clay_RenderCommandArray renderCommands = Clay_EndLayout();

    BeginDrawing();
    Clay_Raylib_Render(renderCommands, &defaultFont);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}

