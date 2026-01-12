#include "entity.h"

Entity::Entity(Vector2 pos, Vector2 size){
    position = pos;
    velocity = {0, 0};
    hitbox = {0, 0, size.x, size.y};
}

Entity::~Entity() 
{ }

Rectangle Entity::getWorldHitbox() const{
    return {hitbox.x + position.x, hitbox.y + position.y, hitbox.width, hitbox.height};
}