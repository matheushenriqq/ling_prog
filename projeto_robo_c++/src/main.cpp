#include "./include/battery.hpp"
#include "./include/info.hpp"
#include "./include/navigation.hpp"
#include "./include/list.hpp"
#include <iostream>
#include <vector>

int main() {
    int total_time = 0;
    int total_gold = 0;
    int total_silver = 0;
    int total_bronze = 0;
    std::vector<std::vector<int>> map_data = get_map(); // Allocate map data
    tList lista = create_list();
    Battery bateria;
    int actual[2] = {0, 0};
    int next_pos[2] = {-1, -1};

    // Clear previous data files
    Info::clear_file("./data/bronze.txt");
    Info::clear_file("./data/charge_impossible.txt");
    Info::clear_file("./data/gold.txt");
    Info::clear_file("./data/list_way.txt");
    Info::clear_file("./data/silver.txt");
    Info::clear_file("./data/charging.txt");
    Info::clear_file("./data/obstacles.txt");

    // Allocate memory for registered positions
    std::vector<Position> registered_positions;
    std::cout << "First Move, 2 seconds\n";
    total_time += MOVE_TIME;
    // Main loop for navigating the map
    while (actual[0] != 7 || actual[1] != 6) {
        // Get the next position
        get_next_pos(map_data, actual, next_pos);

        // Check and generate files if necessary
        Info::charge_impossible(actual);
        Info::list_way(lista, actual);
        total_gold += Info::gold(actual);
        total_silver += Info::silver(actual);
        total_bronze += Info::bronze(actual);
        total_time += bateria.manage_battery_on_move(actual, next_pos);
        Info::obstacles(actual, registered_positions);

        // Update the current position
        actual[0] = next_pos[0];
        actual[1] = next_pos[1];
    }

    // Print the results
    std::cout << "Total gold areas: " << total_gold << "\n";
    std::cout << "Total silver areas: " << total_silver << "\n";
    std::cout << "Total bronze areas: " << total_bronze << "\n";
    std::cout << "Final total time: " << total_time << " seconds\n";
    std::cout << "sucess\n";

    return 0;
}
