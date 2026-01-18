#include "player.h"
#include "collision.h"
#include "map.h"
#include <cmath>

Player::Player(Vector2 pos)
    : Entity(pos, {24, 24})
{
    speed = 200.0f;
}

void Player::update(float dt, const Map& map){
    velocity = {0, 0};

    if (IsKeyDown(KEY_W)) velocity.y -= 1;
    if (IsKeyDown(KEY_S)) velocity.y += 1;
    if (IsKeyDown(KEY_A)) velocity.x -= 1;
    if (IsKeyDown(KEY_D)) velocity.x += 1;

    float len = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
    if (len > 0) {
        velocity.x /= len;
        velocity.y /= len;
    }

    position.x += velocity.x * speed * dt;
    ResolveTileCollision(*this, map, 16);
    position.y += velocity.y * speed * dt;
    ResolveTileCollision(*this, map, 16);
}

void Player::draw(){
    DrawRectangleRec(getWorldHitbox(), BLUE);
}