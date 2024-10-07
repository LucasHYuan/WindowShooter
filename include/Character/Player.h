#pragma once
#include "Character.h"
#include "Utilities/Vector2.h"

class Player : public Character {
public:
    Player(float xPos, float yPos, float w, float h, float spd);
    void move(Vector2 movement, float deltaTime) override;
    void render(SDL_Renderer* renderer);
    void renderArrow(SDL_Renderer* renderer, int mouseX, int mouseY);  // Method to render the triangle
private:

};