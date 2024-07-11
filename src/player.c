#include "headers.h"

// Function to move the player forward or backward

void movePlayer(Game *game, int direction) {
    double moveSpeed = game->player.moveSpeed * direction;
    double newX = game->player.posX + game->player.dirX * moveSpeed;
    double newY = game->player.posY + game->player.dirY * moveSpeed;

    // Check for collisions (adjust according to your collision function)
    if (!checkCollision(game, newX, game->player.posY)) {
        game->player.posX = newX;
    }
    if (!checkCollision(game, game->player.posX, newY)) {
        game->player.posY = newY;
    }
}

// Function to strafe the player left or right

void strafePlayer(Game *game, int direction) {
    double moveSpeed = game->player.moveSpeed * direction;
    double newX = game->player.posX + game->player.planeX * moveSpeed;
    double newY = game->player.posY + game->player.planeY * moveSpeed;

    // Check for collisions (adjust according to your collision function)
    if (!checkCollision(game, newX, game->player.posY)) {
        game->player.posX = newX;
    }
    if (!checkCollision(game, game->player.posX, newY)) {
        game->player.posY = newY;
    }
}

// Function to rotate the player left or right
void rotatePlayer(Game *game, int direction) {
    double rotSpeed = game->player.rotSpeed * direction;
    double oldDirX = game->player.dirX;
    game->player.dirX = game->player.dirX * cos(rotSpeed) - game->player.dirY * sin(rotSpeed);
    game->player.dirY = oldDirX * sin(rotSpeed) + game->player.dirY * cos(rotSpeed);
    double oldPlaneX = game->player.planeX;
    game->player.planeX = game->player.planeX * cos(rotSpeed) - game->player.planeY * sin(rotSpeed);
    game->player.planeY = oldPlaneX * sin(rotSpeed) + game->player.planeY * cos(rotSpeed);
}
