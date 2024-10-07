#include "Character/Character.h"

Character::Character(float xPos, float yPos, float w, float h, float spd) : x(xPos), y(yPos), width(w), height(h), speed(spd) {
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
}
void Character::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}