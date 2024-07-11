#include "headers.h"

// Function to perform raycasting and draw walls
void performRaycasting(Game *game) {
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        // Calculate ray position and direction
        double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
        double rayDirX = game->player.dirX + game->player.planeX * cameraX;
        double rayDirY = game->player.dirY + game->player.planeY * cameraX;

        // Map position
        int mapX = (int)game->player.posX;
        int mapY = (int)game->player.posY;

        // Length of ray from one x or y-side to next x or y-side
        double sideDistX, sideDistY;

        // Length of ray from current position to next x or y-side
        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double perpWallDist;

        // Direction to go in x and y
        int stepX, stepY;

        int hit = 0; // Was there a wall hit?
        int side; // Was a NS or a EW wall hit?

        // Calculate step and initial sideDist
        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (game->player.posX - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - game->player.posX) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (game->player.posY - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - game->player.posY) * deltaDistY;
        }

        // Perform DDA
        while (hit == 0) {
            // Jump to next map square, OR in x-direction, OR in y-direction
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            // Check if ray has hit a wall
            if (game->map[mapX][mapY] > 0) hit = 1;
        }

        // Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
        if (side == 0)
            perpWallDist = (mapX - game->player.posX + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - game->player.posY + (1 - stepY) / 2) / rayDirY;

        // Calculate height of line to draw on screen
        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

        // Calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

        // Choose wall color
        SDL_Color color;
        switch(game->map[mapX][mapY]) {
            case 1: color = (side == 1) ? (SDL_Color){255, 0, 0, 255} : (SDL_Color){127, 0, 0, 255}; break; // Red
            case 2: color = (side == 1) ? (SDL_Color){0, 255, 0, 255} : (SDL_Color){0, 127, 0, 255}; break; // Green
            case 3: color = (side == 1) ? (SDL_Color){0, 0, 255, 255} : (SDL_Color){0, 0, 127, 255}; break; // Blue
            case 4: color = (side == 1) ? (SDL_Color){255, 255, 0, 255} : (SDL_Color){127, 127, 0, 255}; break; // Yellow
            default: color = (side == 1) ? (SDL_Color){255, 255, 255, 255} : (SDL_Color){127, 127, 127, 255}; break; // White
        }

        // Draw the pixels of the stripe as a vertical line
        drawVerticalLine(game, x, drawStart, drawEnd, color);
    }
}
