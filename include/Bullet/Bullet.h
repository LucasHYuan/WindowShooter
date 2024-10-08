#pragma once
#include <SDL.h>
#include "Utilities/Vector2.h"

class Bullet {
public:
    Bullet(float xPos, float yPos, float angle);
    ~Bullet() = default;
    void update(float deltaTime);
    void render(SDL_Renderer* renderer);
    bool isActive() const;
    SDL_Rect getHitbox() const;
private:
    Vector2 position;
    Vector2 velocity;
    float speed;
    bool active;
    SDL_Rect hitbox;

};