#include "headers.h"
#include "headers.h"

void handleKeydown(Game *game, int key) {
    switch (key) {
        case SDLK_w: game->player.moveForward = true; break;
        case SDLK_s: game->player.moveBackward = true; break;
        case SDLK_a: game->player.moveLeft = true; break;
        case SDLK_d: game->player.moveRight = true; break;
        case SDLK_LEFT: game->player.rotateLeft = true; break;
        case SDLK_RIGHT: game->player.rotateRight = true; break;
        // Add more cases as needed
    }
}

void handleKeyup(Game *game, int key) {
    switch (key) {
        case SDLK_w: game->player.moveForward = false; break;
        case SDLK_s: game->player.moveBackward = false; break;
        case SDLK_a: game->player.moveLeft = false; break;
        case SDLK_d: game->player.moveRight = false; break;
        case SDLK_LEFT: game->player.rotateLeft = false; break;
        case SDLK_RIGHT: game->player.rotateRight = false; break;
        // Add more cases as needed
    }
}

void updateGame(Game *game) {
    if (game->player.moveForward) {
        movePlayer(game, 1);
    }
    if (game->player.moveBackward) {
        movePlayer(game, -1);
    }
    if (game->player.moveLeft) {
        strafePlayer(game, -1);
    }
    if (game->player.moveRight) {
        strafePlayer(game, 1);
    }
    if (game->player.rotateLeft) {
        rotatePlayer(game, -1);
    }
    if (game->player.rotateRight) {
        rotatePlayer(game, 1);
    }

    // Handle camera rotation
    if (game->player.rotateLeft) {
        rotatePlayer(game, -1);
    }
    if (game->player.rotateRight) {
        rotatePlayer(game, 1);
    }

    // Additional game logic (e.g., collision detection)
    handleCollisions(game);
}
void handleCollisions(Game *game) {
	(void)game; // Explicitly mark parameter as unused
    // Implement collision handling logic here
}
