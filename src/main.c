#define CLAY_IMPLEMENTATION
#include "../include/clay/clay.h"
#include <stdlib.h>
#include <stdint.h>
#include <raylib.h>
#include "../include/clay/clay.h"
#include "./models/components/components.h"
#include "../include/renderer/clay_renderer_raylib.c"
#include "../src/utils/utils.h"


const int MAX_FONTS = 4;  // example number of fonts you have
Font userFonts[4]; 
const int FONT_ID_BODY = 0;

void ErrorHandler(Clay_ErrorData error) {
  printf("Error: %s \n", "something happened");
}

int main() {
  AppContext context = StartApplication();
  
  SetConfigFlags(FLAG_MSAA_4X_HINT);

  Clay_Raylib_Initialize(1140, 900, "uvmod", FLAG_WINDOW_RESIZABLE);
  uint64_t totalMemorySize = Clay_MinMemorySize();
  Font defaultFont = LoadFont("fonts/Helvetica.ttf");
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

  Font fonts[1];
  fonts[FONT_ID_BODY] = LoadFontEx("fonts/Helvetica.ttf", 48, 0, 400);
  SetTextureFilter(fonts[FONT_ID_BODY].texture, TEXTURE_FILTER_BILINEAR);
  Clay_SetMeasureTextFunction(Raylib_MeasureText, fonts);

  while (!WindowShouldClose()) {
    Clay_SetLayoutDimensions((Clay_Dimensions) {
      .width  = GetScreenWidth(),
      .height = GetScreenHeight(),
    });

    Vector2 mousePosition = GetMousePosition();
    Vector2 scrollDelta = GetMouseWheelMoveV();
    
    Clay_SetPointerState(
      (Clay_Vector2) { mousePosition.x, mousePosition.y },
      IsMouseButtonDown(0)
    );
    
    Clay_UpdateScrollContainers(
      true,
      (Clay_Vector2) { scrollDelta.x, scrollDelta.y },
      GetFrameTime()
    );

    Clay_BeginLayout();
    CLAY({
      .id = CLAY_ID("outer-container"),
      .backgroundColor = {43, 41, 51, 255},
      .layout = {
        .layoutDirection = CLAY_TOP_TO_BOTTOM,
        .childGap = 16,
        .padding = {16, 16, 16, 16},
        .sizing = {
          .width = CLAY_SIZING_GROW(0),
          .height = CLAY_SIZING_GROW(0),
        }
      }

    }) {
      TopMenuBar(&context);
      CLAY({
        .id = CLAY_ID("lower-container"),
        .layout = {
          .layoutDirection = CLAY_LEFT_TO_RIGHT,
          .childGap = 16,
          .sizing = {
            .width = CLAY_SIZING_GROW(0),
            .height = CLAY_SIZING_GROW(0),
          }
        },
      }) {
        SideBar(&context);
        MainContent(&context);
      }
    }
    Clay_RenderCommandArray renderCommands = Clay_EndLayout();

    BeginDrawing();
    ClearBackground(BLACK);
    Clay_Raylib_Render(renderCommands, &defaultFont);
    EndDrawing();
  }
 
  CloseWindow();
  return 0;
}

