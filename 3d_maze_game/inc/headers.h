#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Define constants
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define TEX_WIDTH 64
#define TEX_HEIGHT 64

// Structs for various components
typedef struct {
    double posX, posY;      // Player's position
    double dirX, dirY;      // Player's direction vector
    double planeX, planeY;  // Camera plane

    double moveSpeed;
    double rotSpeed;
    bool moveForward;
    bool moveBackward;
    bool moveLeft;
    bool moveRight;
    bool rotateLeft;
    bool rotateRight;
} Player;

typedef struct {
    int x, y;               // Map position
    double sideDistX, sideDistY; // Distance to next side
    double deltaDistX, deltaDistY; // Distance between sides
    double perpWallDist;    // Perpendicular distance to wall
    int stepX, stepY;       // Step direction
    int hit;                // Wall hit flag
    int side;               // Wall side (NS or EW)
} Ray;

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *textures[3];
    SDL_Surface *screenSurface;
    int **map;              // Map grid
    Player player;          // Player instance
} Game;


typedef struct {
    // Define your Map structure members here
} Map;

// Function prototypes
// init.c
bool initSDL(Game *game);// If the function should return a bool
bool initGame(Game *game);
void closeSDL(Game *game);
bool loadTextures(Game *game);

// raycasting.c
void performRaycasting(Game *game);

// movement.c
void handleMovement(Game *game, const Uint8 *keystate);

// collision.c
bool checkCollision(Game *game, double x, double y);

// parser.c
void loadMap(Game *game, const char *filePath);

// rendering.c
void renderGame(Game *game);

// textures.c
SDL_Texture* loadTexture(Game *game, const char *path);

// utils.c
void freeMap(int **map);

// In headers.h
void setPixel(Game *game, int x, int y, SDL_Color color);

// Function declarations
void movePlayer(Game *game, int direction);
void strafePlayer(Game *game, int direction);
void rotatePlayer(Game *game, int direction);
void handleKeydown(Game *game, int key);
void handleKeyup(Game *game, int key);
void updateGame(Game *game);
void handleCollisions(Game *game);

#endif // HEADERS_H
