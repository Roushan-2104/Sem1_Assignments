#include <stdio.h>
#include <windows.h> // Required for Sleep()

int main() {
    int i, j;

    // --- PART 1: THE ROOF ---
    printf("\n");
    Sleep(300);

    for (i = 0; i < 12; i++) {
        printf("\t");

        // Print leading spaces (decreases by 1 each row)
        // Starts at 11 spaces, goes down to 0
        for (j = 0; j < 11 - i; j++) {
            printf(" ");
        }

        printf("/");

        // Print inner spaces (increases by 2 each row)
        // Starts at 0 spaces, goes up to 22
        for (j = 0; j < 2 * i; j++) {
            printf(" ");
        }

        printf("\\\n");
        Sleep(300);
    }

    // The roof base line
    printf("\t");
    for (i = 0; i < 24; i++) {
        printf("-");
    }
    printf("\n");
    Sleep(300);

    // --- PART 2: THE WALLS (BODY) ---
    // We define the patterns for the interior of the house
    const char *walls[] = {
        "  _____        _____  ", // Top of windows
        " |__|__|      |__|__| ", // Window grids
        " |__|__|      |__|__| ", // Window grids
        "                      ", // Empty wall
        "                      ", // Empty wall
        "         ____         ", // Top of door
        "        |    |        ", // Door sides
        "        |    |        "  // Door sides
    };

    // Calculate how many rows are in our walls array
    int wall_rows = sizeof(walls) / sizeof(walls[0]);

    for (i = 0; i < wall_rows; i++) {
        // \b moves back one char, \t tabs over. 
        // We keep this structure to match exact alignment.
        printf("\b\t|%s|", walls[i]); 
        printf("\n");
        Sleep(300);
    }

    // --- PART 3: THE FLOOR ---
    printf("\b\t|");
    
    printf("________|____|________");
    printf("|\n");
    Sleep(300);

    printf("\n");
    return 0;
}