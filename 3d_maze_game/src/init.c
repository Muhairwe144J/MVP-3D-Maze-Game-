#include "headers.h"

// Function to initialize SDL and create the game window and renderer
bool initSDL(Game *game) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Create window
    game->window = SDL_CreateWindow("3D Maze Game",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);
    if (game->window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Create renderer
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if (game->renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Initialize PNG loading
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    game->screenSurface = SDL_GetWindowSurface(game->window);
    return true;
}

// Function to load textures
bool loadTextures(Game *game) {
    game->textures[0] = loadTexture(game, "assets/textures/wall.png");
    game->textures[1] = loadTexture(game, "assets/textures/ground.png");
    game->textures[2] = loadTexture(game, "assets/textures/ceiling.png");

    for (int i = 0; i < 3; ++i) {
        if (game->textures[i] == NULL) {
            return false;
        }
    }

    return true;
}

// Function to initialize the game
bool initGame(Game *game) {
    if (!initSDL(game)) {
        return false;
    }

    if (!loadTextures(game)) {
        return false;
    }

    return true;
}

// Function to free textures and destroy window and renderer
void closeSDL(Game *game) {
    // Free loaded images
    for (int i = 0; i < 3; ++i) {
        SDL_DestroyTexture(game->textures[i]);
        game->textures[i] = NULL;
    }

    // Destroy renderer and window
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    game->renderer = NULL;
    game->window = NULL;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
