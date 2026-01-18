#include "tileRender.h"

Color getTileColor(TileType type){
    switch (type)
    {
        case TileType::Floor: return DARKGRAY;
        case TileType::Wall: return GRAY;
        case TileType::Water: return BLUE;
        default: return BLACK;
    }
}