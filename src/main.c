#include "raylib.h"
#include "resource_dir.h" // utility header for SearchAndSetResourceDir
#include <math.h>
#include <stdio.h>

typedef enum { BLOCK, CAR } TileType;
#define GRID_SIZE 20
#define CELL_SIZE 45

int main() {
  const int w = 800;
  const int h = 800;
  const char *const title = "Hello Raylib";
  const char *const raylib_version = RAYLIB_VERSION;
  SearchAndSetResourceDir("resources");

  SetTargetFPS(30);

  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
  InitWindow(w, h, title);

  Texture2D block = LoadTexture("block.png");
  Texture2D car = LoadTexture("car1.png");
  Texture2D textures[] = {block, car};

  Vector2 pos = {200.0, 200.0};
  float size = 45.0f;

  float w_hex_offset = block.width;
  float center_hex = block.width;
  float vert_offset = (3.0 / 4.0) * block.height;

  int map[10][10] = {{BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
                     {BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
                     {BLOCK, BLOCK, CAR, BLOCK, BLOCK},
                     {BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
                     {BLOCK, BLOCK, BLOCK, BLOCK, BLOCK}};

  size_t size_row = sizeof(map) / sizeof(map[0]);
  size_t size_col = sizeof(map[0]) / sizeof(map[0][0]);

  Camera2D camera = {0};
  camera.offset = (Vector2){w / 2.0f, h / 2.0f};
  camera.target = (Vector2){GRID_SIZE * size / 2.0f, GRID_SIZE * size / 2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;

  int gW = size_col * size;
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode2D(camera);

    for (int x = 0; x < size_col; x++) {
      for (int y = 0; y < size_row; y++) {
        int col = (y % 2 == 1) ? (x * w_hex_offset) + floor(w_hex_offset / 2.0)
                               : x * w_hex_offset;
        int row = y * vert_offset;
        DrawTexture(textures[map[x][y]], col, row, WHITE);
      }
    }

    EndDrawing();
  }

  UnloadTexture(block);
  UnloadTexture(car);
  CloseWindow();
  return 0;
}
/*
DrawTexture(car, car.width + col, row + floor(car.height / 2.0), WHITE);
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

For a C++ project simply rename the file to .cpp and re-run the build script

-- Copyright (c) 2020-2024 Jeffery Myers
--
--This software is provided "as-is", without any express or implied warranty.
In no event
--will the authors be held liable for any damages arising from the use of this
software.

--Permission is granted to anyone to use this software for any purpose,
including commercial
--applications, and to alter it and redistribute it freely, subject to the
following restrictions:

--  1. The origin of this software must not be misrepresented; you must not
claim that you
--  wrote the original software. If you use this software in a product, an
acknowledgment
--  in the product documentation would be appreciated but is not required.
--
--  2. Altered source versions must be plainly marked as such, and must not be
misrepresented
--  as being the original software.
--
--  3. This notice may not be removed or altered from any source distribution.

*/
