#include <stdio.h>
#include <stdlib.h>
#include "./include/info.h"
#include "./include/navigation.h"

int main() {
    int i;
    int **map_data = get_map();
   

    int actual[2] = {0, 0};
    int next_pos[2] = {-1, -1};

    while (actual[0] != 7 || actual[1] != 2) {
        get_next_pos(map_data, actual, next_pos);

        // Verifique se a posição é válida antes de atualizar
        if (next_pos[0] != -1 && next_pos[1] != -1) {
            printf("Actual Position: (%d,%d)\n", actual[0], actual[1]);
            printf("Next Coordinate: (%d,%d)\n", next_pos[0], next_pos[1]);

            // Verificar e gerar o arquivo se necessário
            charge_impossible(actual);

            // Atualize a posição atual
            actual[0] = next_pos[0];
            actual[1] = next_pos[1];
        } else {
            // Caso contrário, saia do loop ou trate o erro de outra forma
            printf("Invalid next position. Exiting.\n");
            break;
        }
    }
    list_way(actual);
    printf("Reached the target position: (%d,%d)\n", actual[0], actual[1]);
    



    return 0;
}
