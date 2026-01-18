#pragma once
#include "tileType.h"
#include "tileRender.h"
#include "raylib.h"
#include <vector>

class Map
{
    public:
        Map(int width, int height, int tileSize);

        void Generate();
        void Draw() const;
        void makeRectangle(int x, int y, int width, int height, TileType type);
        void makeCircle(int cx, int cy, int r, TileType type);
        bool Walkable(int x, int y) const;
        bool canWalk(Rectangle hitbox) const;
        int getTileSize();

    private:
        int width;
        int height;
        int tileSize;

        std::vector<TileType> tiles;

        int getIndex(int x, int y) const;
};

