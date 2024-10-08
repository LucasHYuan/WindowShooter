#pragma once
#include "Bullet/Bullet.h"
#include <cmath>

Bullet::Bullet(float x, float y, float angle) 
    : position(x, y), speed(400), active(true) {
    velocity.x = cos(angle) * speed;
    velocity.y = sin(angle) * speed;
    hitbox = { (int)x, (int)y, 5, 5 };
}


void Bullet::update(float deltaTime) {
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;

    hitbox.x = static_cast<int>(position.x);
    hitbox.y = static_cast<int>(position.y);

    if (position.x < 0 || position.x > 800 || position.y < 0 || position.y > 600) {
        this->~Bullet();
    }

}

void Bullet::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // White bullet
    SDL_RenderFillRect(renderer, &hitbox);
}

bool Bullet::isActive() const {
    return active;
}

SDL_Rect Bullet::getHitbox() const {
    return hitbox;
}
