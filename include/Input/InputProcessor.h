#pragma once
#include <SDL.h>
#include "Utilities/Vector2.h"
class InputProcessor {
public:
    InputProcessor() = default;
    Vector2 processInput(const Uint8* state);  // Returns the movement vector
};