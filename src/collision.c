#include "headers.h"

// Check if the given position is a wall
int isWall(Game *game, double x, double y) {
    if (game->map[(int)x][(int)y] > 0) return 1;
    return 0;
}

// Function to check collision
bool checkCollision(Game *game, double x, double y) {
    return isWall(game, x, y);
}
