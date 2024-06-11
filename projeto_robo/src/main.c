#include <stdio.h>
#include <stdlib.h>
#include "./include/info.h"
#include "./include/navigation.h"
#include "./include/list.h"
#include "./include/battery.h"

int main() {
    int i;
    int **map_data = get_map();
    tList lista = create_list();
    Battery bateria;

    int actual[2] = {1, 1};
    int next_pos[2] = {-1, -1};

    clear_file("./data/bronze.txt");
    clear_file("./data/charge_impossible.txt");
    clear_file("./data/gold.txt");
    clear_file("./data/list_way.txt");
    clear_file("./data/silver.txt");

    while (actual[0] != 7 || actual[1] != 6) {
        get_next_pos(map_data, actual, next_pos);

        // Verifique se a posição é válida antes de atualizar
        if (next_pos[0] != -1 && next_pos[1] != -1) {
            printf("Actual Position: (%d,%d)\n", actual[0], actual[1]);
            printf("Next Coordinate: (%d,%d)\n", next_pos[0], next_pos[1]);

            // Verificar e gerar o arquivo se necessário
            charge_impossible(actual);
            list_way(&lista, actual);
            gold(actual);
            silver(actual);
            bronze(actual);
            manage_battery_on_move (get_map, &bateria, actual, next_pos);
            // Atualize a posição atual
            actual[0] = next_pos[0];
            actual[1] = next_pos[1];
        } else {
            // Caso contrário, saia do loop ou trate o erro de outra forma
            printf("Invalid next position. Exiting.\n");
            break;
        }
    }
    
    printf("Reached the target position: (%d,%d)\n", actual[0], actual[1]);
    



    return 0;
}
