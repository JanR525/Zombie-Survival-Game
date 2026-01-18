#include "map.h"

Map::Map(int w, int h, int size) 
    : width(w), height(h), tileSize(size)
{
    tiles.resize(width * height, TileType::Empty);
}

int Map::getIndex(int x, int y) const{
    return y * width + x;
}

int Map::getTileSize(){
    return tileSize;
}

void Map::Generate(){
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            if(x == 0 || y == 0 || x == (width - 1) || y == (height - 1))
            {
                tiles[getIndex(x, y)] = TileType::Wall;
            }
            else
            {
                int r = GetRandomValue(0, 100);
                tiles[getIndex(x, y)] = TileType::Floor;
            }
        }
    }
}

void Map::Draw() const{
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            TileType tile = tiles[getIndex(x, y)];

            DrawRectangle(x * tileSize, y * tileSize, tileSize, tileSize, getTileColor(tile));
        }
    }
}

void Map::makeRectangle(int x, int y, int width, int height, TileType type){
    for(int iy = y; iy < y + height; iy++)
    {
        for(int ix = x; ix < x + width; ix++)
        {
            tiles[getIndex(ix, iy)] = type;
        }
    }
}

void Map::makeCircle(int cx, int cy, int r, TileType type)
{
    for (int y = -r; y <= r; y++)
        for (int x = -r; x <= r; x++)
            if (x*x + y*y <= r*r)
                tiles[getIndex(cx + x, cy + y)] = type;
}

bool Map::Walkable(int x, int y) const{
    if (x < 0 || y < 0 || x >= width || y >= height)
        return false;

    TileType tile = tiles[getIndex(x, y)];
    
    return tile == TileType::Floor;
}