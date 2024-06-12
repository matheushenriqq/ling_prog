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
    
    
    int y = next_pos[1];
    int x = next_pos[0];

    if (y >= 0 && y < map->sz_x && x >= 0 && x < map->sz_y) {
        int cell = map->map_data [8 - y][x];
        int level = battery_level(battery);

        if (cell == 255) { // Área navegável
            if (level > 0) {
                pop(battery);
                actual[0] = x;
                actual[1] = y;
                printf("Moved to (%d, %d), Battery: %d\n", actual[0], actual[1], battery_level(battery));
            } else {
                printf("Battery empty! Cannot move to (%d, %d)\n", x, y);
            }
        } else if (cell == 1) { // Área com impossibilidade de carga
            if (level > 0) {
                pop(battery);
                actual[0] = x;
                actual[1] = y;
                printf("Moved to (%d, %d), Battery: %d\n", actual[0], actual[1], battery_level(battery));
            } else {
                printf("Battery empty! Cannot move to (%d, %d)\n", x, y);
            }
        } else if (cell == 0) { // Obstáculo
            printf("Obstacle at (%d, %d). Cannot move.\n", x, y);
        }

        // Verifica se precisa recarregar
        if (cell != 1 && (level <= 1 || (level <= 2 && map->map_data[8 - actual[0]][actual[1]] == 1))) {
            printf("Battery low. Charging at (%d, %d)\n", actual[0], actual[1]);
            while (!is_full(battery)) {
                push(battery, 1);
                printf("Battery: %d\n", battery_level(battery));
                sleep(1); // Simulate 1 second per charge unit
            }
        }

    }
}
