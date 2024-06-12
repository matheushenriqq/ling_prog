#include <stdio.h>
#include <stdlib.h>
#include "./include/navigation.h"
#include "./include/list.h"
#include "./include/battery.h"

int main() {
    int i;
    int **map_data = get_map();
    tList lista = create_list();
    Battery bateria;

    int actual[2] = {0, 0};
    int next_pos[2] = {-1, -1};

    clear_file("./data/bronze.txt");
    clear_file("./data/charge_impossible.txt");
    clear_file("./data/gold.txt");
    clear_file("./data/list_way.txt");
    clear_file("./data/silver.txt");

    while (actual[0] != 7 || actual[1] != 6) {

        manage_battery_on_move(&map_data, &bateria, actual,next_pos);
        get_next_pos(map_data, actual, next_pos);

        // Verifique se a posição é válida antes de atualizar
    
            
            printf("Next Coordinate: (%d,%d)\n", next_pos[0], next_pos[1]);

            // Verificar e gerar o arquivo se necessário
            charge_impossible(actual);
            list_way(&lista, actual);
            gold(actual);
            silver(actual);
            bronze(actual);
            // Atualize a posição atual
            actual[0] = next_pos[0];
            actual[1] = next_pos[1];
        
    }
    
    printf("Reached the target position: (%d,%d)\n", actual[0], actual[1]);
    



    
}
