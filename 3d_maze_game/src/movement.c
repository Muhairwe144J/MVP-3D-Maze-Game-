#include "headers.h"

// Function to update the player's position and direction
void updatePlayerPosition(Game *game, SDL_Event *event) {
    if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
            case SDLK_w: movePlayer(game, 1); break;
            case SDLK_s: movePlayer(game, -1); break;
            case SDLK_a: strafePlayer(game, -1); break;
            case SDLK_d: strafePlayer(game, 1); break;
            case SDLK_LEFT: rotatePlayer(game, -1); break;
            case SDLK_RIGHT: rotatePlayer(game, 1); break;
        }
    }
}
