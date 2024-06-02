#include "./include/navigation.h"
#include "./include/list.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    
    tPos actual = {0, 0}; // Starting position of the robot
    tPos next;
    int **map_data = get_map();

    while (1) {
        printf("Actual position: (%d, %d)\n", actual.x, actual.y);
        

        // Determine the next position
        int found_next = 0;
        tPos possible_moves[4] = {
            {actual.x, actual.y - 1}, // Up
            {actual.x, actual.y + 1}, // Down
            {actual.x - 1, actual.y}, // Left
            {actual.x + 1, actual.y}  // Right
        };

        for (int i = 0; i < 4; i++) {
            int nx = possible_moves[i].x;
            int ny = possible_moves[i].y;

            // Check if the move is within the bounds and not to a cell with color 0
            if (nx >= 0 && nx < MAX_ROWS && ny >= 0 && ny < MAX_COLS && map_data[nx][ny] != 0) {
                next = possible_moves[i];
                found_next = 1;
                break;
            }
        }

    tList list = create_list(); // Criando as listas de diario
    


    int actual[2] = {0, 0};
    int next_pos[2] = {-1, -1};
    
    get_next_pos(map_data, actual, next_pos);
    if (next_pos[0] != -1 && next_pos[1] != -1) { // Check for invalid position
        printf("Next Coordinate: (%d,%d)\n", next_pos[0], next_pos[1]);
    }

    return 0;
}
}