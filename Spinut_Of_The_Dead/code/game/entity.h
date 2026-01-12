#pragma once

#include "raylib.h"

class Entity
{
    public:
        Entity(Vector2 postion, Vector2 size);

        Vector2 position;
        Vector2 velocity;
        Rectangle hitbox;

        virtual void update(float dt) = 0;
        virtual void draw() = 0;

        virtual ~Entity();

        Rectangle getWorldHitbox() const;
};