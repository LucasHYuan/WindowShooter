#include <SDL.h>
#include <iostream>
#include "Character/Player.h"
#include "Input/InputProcessor.h"


const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main(int argc, char* argv[]) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow(  "Window Shooter",
                                            SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED,
                                            WINDOW_WIDTH, WINDOW_HEIGHT,
                                            SDL_WINDOW_SHOWN );
    if(window == nullptr){
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    bool isRunning = true;
    SDL_Event event;
    const Uint8* state = SDL_GetKeyboardState(NULL);

    InputProcessor inputProcessor;
    
    #pragma region Game Loop Tickers
    Uint32 lastTime = SDL_GetTicks();
    Uint32 currentTime;
    float deltaTime;
    #pragma endregion
    
    Player player(100, 100, 50, 50, 200);

    while(isRunning){

        currentTime = SDL_GetTicks();
        deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                isRunning = false;
            }
            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_ESCAPE){
                    isRunning = false;
                }
            }
        }


        int mouseX, mouseY;
        Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);
        // Process input and get movement vector
        Vector2 movement = inputProcessor.processInput(state);
        
        // Update and render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            // std::cout << "Mouse X: " << mouseX << " Mouse Y: " << mouseY << std::endl;
            player.shoot(mouseX, mouseY);
        }
        player.update(deltaTime);
        player.move(movement, deltaTime);
        player.render(renderer);
        player.renderArrow(renderer, mouseX, mouseY);


        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
