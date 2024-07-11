#include "headers.h"

// Function to load the map from a file
void loadMap(Game *game, const char *filePath) {
	(void)game;// Explicitly mark parameter as unused

    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Failed to open map file: %s\n", filePath);
        exit(EXIT_FAILURE);
    }

    char line[256];
    int row = 0;

    while (fgets(line, sizeof(line), file)) {
        for (size_t col = 0; col < strlen(line); col++) {
            if (line[col] == '1') {
                game->map[row][col] = 1;
            } else {
                game->map[row][col] = 0;
            }
        }
        row++;
    }

    fclose(file);
}
