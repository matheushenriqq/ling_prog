#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "navigation.h"

#ifndef BATTERY_H
#define BATTERY_H

// Definições para a bateria
#define MAX_BATTERY 4

typedef struct {
    int stack[MAX_BATTERY];
    int top;
} Battery;

// Inicializa a bateria com capacidade máxima
void init_battery(Battery* battery);

// Verifica se a bateria está vazia
int is_empty(Battery* battery);

// Verifica se a bateria está cheia
int is_full(Battery* battery);

// Empilha (recarrega) uma unidade de bateria
void push(Battery* battery, int value);

// Desempilha (consome) uma unidade de bateria
int pop(Battery* battery);

// Obtém o nível atual da bateria
int battery_level(Battery* battery);

// Função de gerenciamento da bateria ao mover o robô
void manage_battery_on_move(tMap* map, Battery* battery, int* actual, int* next_pos);

#endif /* ROBOT_H */
