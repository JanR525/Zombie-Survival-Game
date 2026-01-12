#pragma once 
#include "entity.h"
#include "map.h"

class Player : public Entity {
    public:
        float speed;

        Player(Vector2 pos);

        void update(float dt, const Map& map);
        void draw() override;
};