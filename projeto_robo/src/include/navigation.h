#ifndef NAVIGATION_H
#define NAVIGATION_H

#define MAX_COORDS 1000 // Maximum number of coordinates
#define MAX_ROWS 100 // Maximum number of map rows
#define MAX_COLS 100 // Maximum number of map cols

typedef struct map {
    int sz_x;
    int sz_y;
    int map_data[MAX_ROWS][MAX_COLS]; 
} tMap;

typedef struct pos {
    int x;
    int y;
} tPos;

typedef struct path {
    int num_coords;
    tPos path[MAX_COORDS];
} tPath;

int **get_map(void);
int get_next_pos(int **map_data, int *actual, int *next_pos);
void print_map(void);
void gold(int actual[2]);
void silver(int actual[2]);
void charge_impossible(int actual[2]);
void bronze(int actual[2]);
void clear_file(const char *filepath);

#endif /* NAVIGATION_H */
