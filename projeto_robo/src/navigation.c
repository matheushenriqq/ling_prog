#include "./include/navigation.h"

#include "./include/list.h"
#include <stdio.h>
#include <stdlib.h>


#define MAX_COORDS 1000 // Maximum number of coordinates
#define MAX_ROWS 100 // Maximum number of map rows
#define MAX_COLS 100 // Maximum number of map cols

tPath read_coordinates(void) {
    tPath path;

    FILE *file = fopen("./data/path.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!");
        exit(1);
    }

    // Read the number of coordinates from the first line
    fscanf(file, "%d", &path.num_coords);

    // Read each coordinate and store it in the array
    for (int i = 0; i < path.num_coords; i++) {
        fscanf(file, "%d, %d", &path.path[i].x, &path.path[i].y);
    }

    fclose(file);
    return path;
}

tMap read_map_from_file(void) {
    tMap map;
    FILE *file = fopen("./data/map.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!");
        exit(1);
    }

    // Read the number of rows and columns
    fscanf(file, "%d %d", &map.sz_x, &map.sz_y);

    // Read the map data
    for (int i = 0; i < map.sz_x; i++) {
        for (int j = 0; j < map.sz_y; j++) {
            fscanf(file, "%d", &map.map_data[i][j]);
        }
    }

    fclose(file);
    return map;
}

int **get_map() {
    tMap map = read_map_from_file();
    int **map_data = (int **)malloc(map.sz_x * sizeof(int *));
    if (map_data == NULL) {
        fprintf(stderr, "Error allocating memory for map data!");
        exit(1);
    }
    for (int i = 0; i < map.sz_x; i++) {
        map_data[i] = (int *)malloc(map.sz_y * sizeof(int));
        if (map_data[i] == NULL) {
            fprintf(stderr, "Error allocating memory for map data!");
            exit(1);
        }
        for (int j = 0; j < map.sz_y; j++) {
            map_data[i][j] = map.map_data[i][j];
        }
    }
    return map_data;
}

int get_next_pos(int **map_data, int *actual, int *next_pos) {
    tPath path = read_coordinates();

    for (int i = 0; i < path.num_coords - 1; i++) {
        if (path.path[i].x == actual[0] && path.path[i].y == actual[1]) {
            next_pos[0] = path.path[i+1].x;
            next_pos[1] = path.path[i+1].y;
            return 0;
        }
    }

    fprintf(stderr, "Error! Unable to find next position!\n");
    // Return an invalid position or use an error code
    next_pos[0] = -1;
    next_pos[1] = -1;
    exit(1);
}

void print_map(void) {
    tMap map = read_map_from_file();
    printf("Size X: %d\n", map.sz_x);
    printf("Size Y: %d\n", map.sz_y);
    printf("Map Data:\n");
    for (int i = 0; i < map.sz_x; i++) {
        for (int j = 0; j < map.sz_y; j++) {
            printf("%d ", map.map_data[i][j]);
        }
        printf("\n");
    }
}

#include <stdio.h>

void clear_file(const char *filepath) {
    FILE *file = fopen(filepath, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    // No need to write anything; opening in "w" mode clears the file
    fclose(file);
    printf("File %s cleared.\n", filepath);
}

void charge_impossible(int actual[2]) {
    // Ler o mapa do arquivo
    tMap map = read_map_from_file();

    // Obter a matriz de dados do mapa
    int **map_data = get_map();

    // Obter a posição atual
    int y = actual[1];
    int x = actual[0];

    // Verificar se a cor na posição atual é igual a 1
    if (map.map_data[8 - y][x] == 1) {
        int color = map.map_data[8 - y][x];

        printf("Checking color at position (%d, %d): %d\n", x, y, color);

        // Abrir o arquivo para escrita
        FILE *file = fopen("./data/charge_impossible.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever a cor no arquivo
        fprintf(file, "Color %d found at position (%d, %d)\nImposible to charge\n", color, x, y);
        fclose(file);

        printf("Color %d found at position (%d, %d) and written to file.\n", color, x, y);
    }
}

void list_way(tList *list, int actual[2]) {

    // Ler o mapa do arquivo
    tMap map = read_map_from_file();

    // Obter a matriz de dados do mapa
    int **map_data = get_map();

    // Obter a posição atual
    int y =  actual[1];
    int x =  actual[0];

    int color = map.map_data[8 - y][x];
    switch (color)
    {
    case 255: insert_list(list, "free_2_go"); break;
    case 191: insert_list(list, "gold"); break;
    case 127: insert_list(list, "silver"); break;
    case 63:  insert_list(list, "bronze"); break;
    case 1:   insert_list(list, "charge_impossible"); break;  
    }

    tNode* current = list->first_elem;

    FILE *file = fopen("./data/list_way.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "List elements:\n");
    while (current != NULL) {
        fprintf(file, "%s\n", current->data);
        current = current->next;
    }

    fclose(file);
}
    
void gold(int actual[2]) {
    // Ler o mapa do arquivo
    tMap map = read_map_from_file();

    // Obter a matriz de dados do mapa
    int **map_data = get_map();

    // Obter a posição atual
    int y = actual[1];
    int x = actual[0];

    // Verificar se a cor na posição atual é igual a 1
    if (map.map_data[8 - y][x] == 191) {
        int color = map.map_data[8 - y][x];

        printf("Checking color at position (%d, %d): %d\n", x, y, color);

        // Abrir o arquivo para escrita
        FILE *file = fopen("./data/gold.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever a cor no arquivo
        fprintf(file, "Color %d found at position (%d, %d)\ngold\n", color, x, y);
        fclose(file);

        printf("Color %d found at position (%d, %d) and written to file.\n", color, x, y);
    }
}

void silver(int actual[2]) {
    // Ler o mapa do arquivo
    tMap map = read_map_from_file();

    // Obter a matriz de dados do mapa
    int **map_data = get_map();

    // Obter a posição atual
    int x =  actual[0];
    int y =  actual[1];

    // Verificar se a cor na posição atual é igual a 1
    if (map.map_data[8 - y][x] == 127) {
        int color = map.map_data[8 - y][x];

        printf("Checking color at position (%d, %d): %d\n", x, y, color);

        // Abrir o arquivo para escrita
        FILE *file = fopen("./data/silver.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever a cor no arquivo
        fprintf(file, "Color %d found at position (%d, %d)\nsilver\n", color, x, y);
        fclose(file);

        printf("Color %d found at position (%d, %d) and written to file.\n", color, x, y);
    }
}

void bronze(int actual[2]) {
    // Ler o mapa do arquivo
    tMap map = read_map_from_file();

    // Obter a matriz de dados do mapa
    int **map_data = get_map();

    // Obter a posição atual
    int x = actual[0];
    int y = actual[1];

    // Verificar se a cor na posição atual é igual a 63
    if (map.map_data[8 - y][x] == 63) {
        int color = map.map_data[8 - y][x];

        printf("Checking color at position (%d, %d): %d\n", x, y, color);

        // Abrir o arquivo para escrita
        FILE *file = fopen("./data/bronze.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever a cor no arquivo
        fprintf(file, "Color %d found at position (%d, %d)\nbronze\n", color, x, y);
        fclose(file);

        printf("Color %d found at position (%d, %d) and written to file.\n", color, x, y);
    }
}