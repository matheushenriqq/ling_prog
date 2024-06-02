#include "../include/navigation.h"
#include <stdio.h>

int main() {

    int **map_data = get_map();
    printf("Map:\n");
    print_map();

    int actual[2] = {2, 1};
    int next_pos[2] = {-1, -1};
    
    get_next_pos(map_data, actual, next_pos);
    if (next_pos[0] != -1 && next_pos[1] != -1) { // Check for invalid position
        printf("Next Coordinate: (%d,%d)\n", next_pos[0], next_pos[1]);
    }

    return 0;
}