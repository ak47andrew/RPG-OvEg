#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create an SDL Window
    SDL_Window* window = SDL_CreateWindow(
        "SDL Example",                  // Title of the window
        SDL_WINDOWPOS_CENTERED,         // X position of the window
        SDL_WINDOWPOS_CENTERED,         // Y position of the window
        800,                            // Width of the window
        600,                            // Height of the window
        SDL_WINDOW_SHOWN                // Window flags
    );

    if (!window) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer for the window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Set renderer color (RGBA: Red, Green, Blue, Alpha)
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue background

    // Clear the screen with the set color
    SDL_RenderClear(renderer);

    // Display the renderer content
    SDL_RenderPresent(renderer);

    // Wait for the user to quit
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }

    // Cleanup resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
