#include "headers.h"

int main(int argc, char *args[]) {
    Game game;

    // Initialize SDL
    if (!initSDL(&game)) {
        printf("Failed to initialize!\n");
        return -1;
    }

    // Load textures
    if (!loadTextures(&game)) {
        printf("Failed to load textures!\n");
        closeSDL(&game);
        return -1;
    }

    // Initialize the game state
    if (!initGame(&game)) {
        printf("Failed to initialize game!\n");
        closeSDL(&game);
        return -1;
    }

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                handleKeydown(&game, e.key.keysym.sym);
            } else if (e.type == SDL_KEYUP) {
                handleKeyup(&game, e.key.keysym.sym);
            }
        }

        // Update game state
        updateGame(&game);

        // Render the scene
        renderGame(&game);

        // Delay to control frame rate
        SDL_Delay(16);
    }

    // Clean up and close SDL
    closeSDL(&game);

    return 0;
}
