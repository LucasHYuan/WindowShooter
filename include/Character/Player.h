#pragma once
#include "Character.h"
#include "Utilities/Vector2.h"
#include <Bullet/Bullet.h>
#include <vector>
class Player : public Character {
public:
    Player(float xPos, float yPos, float w, float h, float spd);
    void move(Vector2 movement, float deltaTime) override;
    void render(SDL_Renderer* renderer);
    void renderArrow(SDL_Renderer* renderer, int mouseX, int mouseY);  // Method to render the triangle
    void shoot(float mouseX, float mouseY);
    void update(float deltaTime);
private:
    std::vector<Bullet> bullets;  // Vector to store the bullets
    float shoot_interval = 1;         // Time interval between consecutive shots
    float time_since_last_shot = 3;   // Tracks time since the last shot
};