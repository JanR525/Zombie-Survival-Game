#include "collision.h"
#include "entity.h"
#include "map.h"
#include <cmath>

inline int WorldToTile(float x, int tileSize){
    return (int) (x / tileSize);
}

void ResolveTileCollision(Entity& e, const Map& map, int tileSize){
    Rectangle box = e.getWorldHitbox();

    int left = WorldToTile(box.x, tileSize);
    int right = WorldToTile(box.x + box.width, tileSize);
    int top = WorldToTile(box.y, tileSize);
    int bottom = WorldToTile(box.y + box.height, tileSize);

    for(int ty = top; ty <= bottom; ty++)
    {
        for(int tx = left; tx <= right; tx++)
        {
            if(map.Walkable(tx, ty)) continue;

            Rectangle tileRect = {
                tx * tileSize,
                ty * tileSize,
                (float)tileSize,
                (float)tileSize
            };

            Rectangle overlap;
            if (CheckCollisionRecs(box, tileRect))
            {
                float dx1 = tileRect.x + tileRect.width - box.x;
                float dx2 = box.x + box.width - tileRect.x;
                float dy1 = tileRect.y + tileRect.height - box.y;
                float dy2 = box.y + box.height - tileRect.y;

                float minX = (dx1 < dx2) ? dx1 : -dx2;
                float minY = (dy1 < dy2) ? dy1 : -dy2;

                if(fabs(minX) < fabs(minY))
                    e.position.x += minX;
                else
                    e.position.y += minY;

                box = e.getWorldHitbox();
            }
        }
    }
}