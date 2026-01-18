#pragma once
#include "raylib.h"
#include "map.h"

inline int WorldToTile(float x, int tileSize);
void ResolveTileCollision(Entity& e, const Map& map, int tileSize);