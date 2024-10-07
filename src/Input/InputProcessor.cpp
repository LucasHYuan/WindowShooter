#include "Input/InputProcessor.h"

Vector2 InputProcessor::processInput(const Uint8* state) {
    Vector2 movement;

    if (state[SDL_SCANCODE_W]) {
        movement.y -= 1;  // Move up
    }
    if (state[SDL_SCANCODE_S]) {
        movement.y += 1;  // Move down
    }
    if (state[SDL_SCANCODE_A]) {
        movement.x -= 1;  // Move left
    }
    if (state[SDL_SCANCODE_D]) {
        movement.x += 1;  // Move right
    }

    return movement;
}
