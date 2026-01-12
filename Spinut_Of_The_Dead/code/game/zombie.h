#pragma once 
#include "entity.h"
#include <vector>

class Zombie : public Entity{
    public:
        float speed;

        Zombie(Vector2 pos);

        void update(float dt, Vector2 playerPos, const std::vector<Zombie>& zombies);
        void update(float dt) override;
        void draw() override;
};