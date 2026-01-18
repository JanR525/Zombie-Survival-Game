#pragma once 
#include "entity.h"
#include "map.h"
#include <vector>

class Zombie : public Entity{
    public:
        float speed;

        Zombie(Vector2 pos);

        void update(float dt, Vector2 playerPos, const std::vector<Zombie>& zombies, const Map& map);
        void update(float dt, const Map& map) override;
        void draw() override;
};