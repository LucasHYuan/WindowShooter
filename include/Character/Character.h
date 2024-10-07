#pragma once
#include <SDL.h>
#include "Utilities/Vector2.h"

class Character {
protected:
    float x, y;
    float width, height;
    float speed;
    SDL_Rect rect;      

public:
    Character(float xPos, float yPos, float w, float h, float spd);
    virtual ~Character() = default;

    virtual void move(Vector2 movement, float deltaTime) = 0;
    void render(SDL_Renderer* renderer);
};
