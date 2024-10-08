#include "Character/Player.h"
#include <iostream>
Player::Player(float xPos, float yPos, float w, float h, float spd) : Character(xPos, yPos, w, h, spd) {
}

void Player::move(Vector2 movement, float deltaTime){
    x += movement.x * speed * deltaTime;
    y += movement.y * speed * deltaTime;

    // Update SDL_Rect position
    rect.x = static_cast<int>(x);
    rect.y = static_cast<int>(y);
    
}

void Player::render(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red player
    SDL_RenderFillRect(renderer, &rect);
    for(auto &bullet : bullets){
        bullet.render(renderer);
    }
}
void Player::renderArrow(SDL_Renderer* renderer, int mouseX, int mouseY){
    float dx = mouseX - (x + width / 2);
    float dy = mouseY - (y + height / 2);
    float angle = atan2(dy, dx);

    // Define the size of the arrow triangle
    float arrowLength = 30.0f;
    float baseWidth = 10.0f;

    // Calculate the vertices of the triangle
    SDL_Point p1 = {(int)(x + width / 2 + cos(angle) * arrowLength),
                    (int)(y + height / 2 + sin(angle) * arrowLength)};  // Tip of the arrow
    SDL_Point p2 = {(int)(x + width / 2 + cos(angle + M_PI / 2) * baseWidth / 2),
                    (int)(y + height / 2 + sin(angle + M_PI / 2) * baseWidth / 2)};  // Left base of the arrow
    SDL_Point p3 = {(int)(x + width / 2 + cos(angle - M_PI / 2) * baseWidth / 2),
                    (int)(y + height / 2 + sin(angle - M_PI / 2) * baseWidth / 2)};  // Right base of the arrow

    // Draw the triangle using SDL_RenderDrawLine
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // Green arrow
    SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
    SDL_RenderDrawLine(renderer, p1.x, p1.y, p3.x, p3.y);
    SDL_RenderDrawLine(renderer, p2.x, p2.y, p3.x, p3.y);
}

void Player::shoot(float mouseX, float mouseY) {
    if (time_since_last_shot >= shoot_interval) {
        float dx = mouseX - (x + width / 2);
        float dy = mouseY - (y + height / 2);
        float angle = atan2(dy, dx);
        Bullet n_bullet = Bullet(x + width / 2, y + height / 2, angle);
        bullets.push_back(n_bullet);
        time_since_last_shot = 0;
    }
}

void Player::update(float deltaTime){
    time_since_last_shot += deltaTime;
    for(auto &bullet : bullets){
        bullet.update(deltaTime);
    }

    bullets.erase(
        std::remove_if(bullets.begin(), bullets.end(),
                       [](const Bullet& b) { return !b.isActive(); }),
        bullets.end());
}