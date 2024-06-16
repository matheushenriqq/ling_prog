#include "./include/battery.hpp"
#include "./include/navigation.hpp"
#include <fstream>

// Construtor para inicializar a bateria com capacidade máxima
Battery::Battery() : top(-1) {
    stack.resize(MAX_BATTERY, 1);
    top = MAX_BATTERY - 1;
}

// Verifica se a bateria está vazia
bool Battery::is_empty() const {
    return top == -1;
}

// Verifica se a bateria está cheia
bool Battery::is_full() const {
    return top == MAX_BATTERY - 1;
}

// Empilha (recarrega) uma unidade de bateria
void Battery::push(int value) {
    if (!is_full()) {
        stack[++top] = value;
    }
}

// Desempilha (consome) uma unidade de bateria
int Battery::pop() {
    if (!is_empty()) {
        return stack[top--];
    }
    return -1; // Indica que a bateria está vazia
}

// Obtém o nível atual da bateria
int Battery::battery_level() const {
    return top + 1;
}

// Função para simular recarregamento de bateria
void Battery::recharge_battery() {
    std::cout << "Recharging battery...\n";
    std::this_thread::sleep_for(std::chrono::seconds(RECHARGE_TIME));
    while (!is_full()) {
        push(1);
    }
    std::cout << "Battery fully recharged. Battery level: " << battery_level() << "\n";
}

// Gerencia a bateria enquanto move o robô
int Battery::manage_battery_on_move(int* actual, int* next_pos) {
    tMap mapa = read_map_from_file();
    if (mapa.map_data.empty()) {
        std::cerr << "Failed to read map data\n";
        return -1; // Indicando erro
    }

    int time = 0;
    int y_bat = next_pos[1];
    int x_bat = next_pos[0];

    if (y_bat < 0 || y_bat >= mapa.sz_y || x_bat < 0 || x_bat >= mapa.sz_x) {
        std::cerr << "Next position out of map bounds\n";
        return -1; // Indicando erro
    }

    int cell = mapa.map_data[8 - y_bat][x_bat];
    int level = battery_level();

    if (cell == 255 || cell == 191 || cell == 127 || cell == 63) { // Áreas navegáveis
        if (level > 1) {
            pop();
            actual[0] = x_bat;
            actual[1] = y_bat;
            std::cout << "Moved to (" << actual[0] << ", " << actual[1] << "), Battery: " << battery_level() << "\n";
            time += MOVE_TIME;
            std::cout << "2 seconds for move\n";
            std::this_thread::sleep_for(std::chrono::seconds(MOVE_TIME));

            // Verifica se a bateria está em 25% ou menos
            if (level - 1 < 2) {
                std::cout << "Battery low. Charging at (" << actual[0] << ", " << actual[1] << ")\n";
                recharge_battery();

                std::ofstream file("./data/charging.txt", std::ios::app);
                if (file) {
                    file << "Charge at (" << x_bat << ", " << y_bat << ")\n";
                } else {
                    std::cerr << "Failed to open charging log file\n";
                }
                time += RECHARGE_TIME;
            }
        } else {
            std::cout << "Not enough battery to move\n";
        }
    } else if (cell == 1) { // Área com impossibilidade de carga
        if (level > 2) {
            pop();
            actual[0] = x_bat;
            actual[1] = y_bat;
            std::cout << "Moved to (" << actual[0] << ", " << actual[1] << "), Battery: " << battery_level() << "\n";
            time += MOVE_TIME;
            std::cout << "2 seconds for move\n";
            std::this_thread::sleep_for(std::chrono::seconds(MOVE_TIME));
        } else {
            std::cout << "Battery too low to move to an area with impossibility of charge\n";
            // Recarrega a bateria antes de se mover
            std::cout << "Battery low. Charging at (" << actual[0] << ", " << actual[1] << ")\n";
            recharge_battery();
            pop();

            std::ofstream file("./data/charging.txt", std::ios::app);
            if (file) {
                file << "Charge at (" << actual[0] << ", " << actual[1] << ")\n";
            } else {
                std::cerr << "Failed to open charging log file\n";
            }
            time += RECHARGE_TIME;
        }
    }

    return time;
}
