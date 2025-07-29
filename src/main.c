#include "raylib.h"

int main() {
  InitWindow(800, 450, "this is a test");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello Ray Ray", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}

