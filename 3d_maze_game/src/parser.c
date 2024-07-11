#include "headers.h"

// Function to parse the map file and load it into the game structure
void parseMap(Game *game, const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open map file %s\n", filePath);
        exit(EXIT_FAILURE);
    }

    char line[256];
    int row = 0;
    while (fgets(line, sizeof(line), file)) {
        for (int col = 0; col < strlen(line); col++) {
            if (line[col] == '1') {
                game->map[row][col] = 1; // Wall
            } else {
                game->map[row][col] = 0; // Empty space
            }
        }
        row++;
    }
    fclose(file);
}
