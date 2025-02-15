#include "game_update.h"
#include "raylib.h"

void GameUpdate(Camera2D *camera, Vector2 *player) {
  // float speed = 5 * GetFrameTime();

  if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
    player->y -= 10;
    camera->target.y -= 10;
  }
  if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
    player->y += 10;
    camera->target.y += 10;
  }

  if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
    player->x -= 10;
    camera->target.x -= 10;
  }
  if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
    player->x += 10;
    camera->target.x += 10;
  }
}
