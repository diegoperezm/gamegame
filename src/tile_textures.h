// tile_textures.h
#ifndef TILE_TEXTURES_H
#define TILE_TEXTURES_H

#include <raylib.h>

#define TILE_LIST                                                              \
  X(BLOCK, "block.png")                                                        \
  X(BLOCK_RIGHT_CORNER, "block_right_corner.png")                              \
  X(BLOCK_LEFT_CORNER, "block_left_corner.png")                                \
  X(BLOCK_TOP, "block_top.png")                                                \
  X(BLOCK_BOTTOM, "block_bottom.png")                                          \
  X(BLOCK_LEFT, "block_left.png")                                              \
  X(BLOCK_RIGHT, "block_right.png")                                            \
  X(BLOCK_BLANK, "block_blank.png")                                            \
  X(CAR, "car1.png")                                                           \
  X(TILE_NUM, "")

typedef enum {
#define X(name, path) name,
  TILE_LIST
#undef X
} TileType;

typedef struct {
  TileType type;
  Texture2D texture;
} TileTexture;

#endif // TILE_TEXTURES_H
