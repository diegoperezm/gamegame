// tile_textures.h
#ifndef TILE_TEXTURES_H
#define TILE_TEXTURES_H

#include <raylib.h>

#define TILE_LIST                                                              \
  X(BLOCK, "../resources/block.png")                                                        \
  X(BLOCK_RIGHT_CORNER, "../resources/block_right_corner.png")                              \
  X(BLOCK_LEFT_CORNER, "../resources/block_left_corner.png")                                \
  X(BLOCK_TOP, "../resources/block_top.png")                                                \
  X(BLOCK_BOTTOM, "../resources/block_bottom.png")                                          \
  X(BLOCK_LEFT, "../resources/block_left.png")                                              \
  X(BLOCK_RIGHT, "../resources/block_right.png")                                            \
  X(BLOCK_BLANK, "../resources/block_blank.png")                                            \
  X(CAR, "../resources/car1.png")                                                           \
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
