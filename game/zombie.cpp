#include "zombie.h"
#include <cmath>

static Vector2 normalize(Vector2 dir){
    float len = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    if (len > 0) {
        return {dir.x/len, dir.y/len};
    }
    return {0,0};
}

Zombie::Zombie(Vector2 pos) : Entity(pos, {24, 24})
{
    speed = 120.0f;
}

void Zombie::update(float dt, Vector2 playerPos, const std::vector<Zombie>& zombies, const Map& map){
    Vector2 dir = {
        playerPos.x - position.x,
        playerPos.y - position.y
    };

    dir = normalize(dir);

    const float separationRadius = 50.0f;
    const float separationStrength = 1.5f;

    Vector2 separation = {0,0};

    for(const Zombie& other : zombies)
    {
        if(&other == this) continue;

        Vector2 diff = {
            position.x - other.position.x,
            position.y - other.position.y
        };

        float distSq = diff.x*diff.x + diff.y*diff.y;
        float minDist = separationRadius * separationRadius;

        if (distSq > 0 && distSq < minDist)
        {
            float dist = std::sqrt(distSq);
            Vector2 away = { diff.x / dist, diff.y / dist };

            separation.x += away.x * (separationRadius - dist);
            separation.y += away.y * (separationRadius - dist);
        }
    }

    separation = normalize(separation);

    Vector2 finalDir = {
        dir.x + separation.x * separationStrength,
        dir.y + separation.y * separationStrength
    };

    finalDir = normalize(finalDir);

    Vector2 oldPos = position;

    position.x += finalDir.x * speed * dt;
    if(!map.canWalk(getWorldHitbox()))
    {
        position.x = oldPos.x;
    }
    position.y += finalDir.y * speed * dt;
    if(!map.canWalk(getWorldHitbox()))
    {
        position.y = oldPos.y;
    }
}

void Zombie::update(float dt, const Map& map){
    (void) dt;
}

void Zombie::draw(){
    DrawRectangleRec(getWorldHitbox(), GREEN);
}