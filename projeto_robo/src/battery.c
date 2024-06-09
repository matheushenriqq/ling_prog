#include <stdio.h>
#include <stdlib.h>
#include "./include/navigation.h"
#include "./include/battery.h"

#define MAX_BATTERY 4


// Inicializa a bateria com capacidade máxima
void init_battery(Battery* battery) {
    battery->top = -1;
    for (int i = 0; i < MAX_BATTERY; i++) {
        battery->stack[++battery->top] = 1; // Cada unidade representa uma unidade de deslocamento
    }
}

// Verifica se a bateria está vazia
int is_empty(Battery* battery) {
    return battery->top == -1;
}

// Verifica se a bateria está cheia
int is_full(Battery* battery) {
    return battery->top == MAX_BATTERY - 1;
}

// Empilha (recarrega) uma unidade de bateria
void push(Battery* battery, int value) {
    if (!is_full(battery)) {
        battery->stack[++battery->top] = value;
    }
}

// Desempilha (consome) uma unidade de bateria
int pop(Battery* battery) {
    if (!is_empty(battery)) {
        return battery->stack[battery->top--];
    }
    return -1; // Indica que a bateria está vazia
}

// Obtém o nível atual da bateria
int battery_level(Battery* battery) {
    return battery->top + 1;
}

#include <unistd.h> // for sleep function


void manage_battery_on_move(tMap* map, Battery* battery, int* actual, int* next_pos) {

    int **map_data = get_map();
    
    
    int row = next_pos[0];
    int col = next_pos[1];

    if (row >= 0 && row < map->sz_x && col >= 0 && col < map->sz_y) {
        int cell = map->map_data [row][col];
        int level = battery_level(battery);

        if (cell == 255) { // Área navegável
            if (level > 0) {
                pop(battery);
                actual[0] = row;
                actual[1] = col;
                printf("Moved to (%d, %d), Battery: %d\n", actual[0], actual[1], battery_level(battery));
            } else {
                printf("Battery empty! Cannot move to (%d, %d)\n", row, col);
            }
        } else if (cell == 1) { // Área com impossibilidade de carga
            if (level > 0) {
                pop(battery);
                actual[0] = row;
                actual[1] = col;
                printf("Moved to (%d, %d), Battery: %d\n", actual[0], actual[1], battery_level(battery));
            } else {
                printf("Battery empty! Cannot move to (%d, %d)\n", row, col);
            }
        } else if (cell == 0) { // Obstáculo
            printf("Obstacle at (%d, %d). Cannot move.\n", row, col);
        }

        // Verifica se precisa recarregar
        if (cell != 1 && (level <= 1 || (level <= 2 && map->map_data[actual[0]][actual[1]] == 1))) {
            printf("Battery low. Charging at (%d, %d)\n", actual[0], actual[1]);
            while (!is_full(battery)) {
                push(battery, 1);
                printf("Battery: %d\n", battery_level(battery));
                sleep(1); // Simulate 1 second per charge unit
            }
        }
    } else {
        printf("Invalid move to (%d, %d)\n", row, col);
    }
}
