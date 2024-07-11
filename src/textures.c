#include "headers.h"

// Load a texture from a BMP file
SDL_Texture* loadTexture(Game *game, const char *path) {
    SDL_Surface *surface = IMG_Load(path);
    if (!surface) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
        return NULL;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

// Function to apply textures to the walls (to be implemented)
void applyTextures(Game *game) {
	 (void)game; // Explicitly mark parameter as unused
    // Implementation to apply textures to the walls
}
