#include "headers.h"

// Function to render the game
void renderGame(Game *game) {
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);

    SDL_RenderPresent(game->renderer);
}

// Function to set a pixel color on the screen
void setPixel(Game *game, int x, int y, SDL_Color color) {
    Uint32 *pixels = (Uint32 *)game->screenSurface->pixels;
    Uint32 pixelColor = SDL_MapRGB(game->screenSurface->format, color.r, color.g, color.b);
    pixels[(y * game->screenSurface->w) + x] = pixelColor;
}

// Function to draw a vertical line on the screen
void drawVerticalLine(Game *game, int x, int y1, int y2, SDL_Color color) {
    for (int y = y1; y <= y2; y++) {
        setPixel(game, x, y, color);
    }
    SDL_RenderPresent(game->renderer);
}
