from battery import Battery
from info import Info
from navigation import Map, Path, Position
from list_module import tList, insert_list, remove_list, free_list, print_list, create_list

def main():
    total_time = 0
    total_gold = 0
    total_silver = 0
    total_bronze = 0
    map_data = Map().get_map()
    lista = create_list()
    bateria = Battery()
    actual = [0, 0]
    next_pos = [-1, -1]
    goal_position = [7, 6]

    # Clear previous data files
    Info.clear_file("./data/bronze.txt")
    Info.clear_file("./data/charge_impossible.txt")
    Info.clear_file("./data/gold.txt")
    Info.clear_file("./data/list_way.txt")
    Info.clear_file("./data/silver.txt")
    Info.clear_file("./data/charging.txt")
    Info.clear_file("./data/obstacles.txt")

    # Allocate memory for registered positions
    registered_positions = []
    path = Path()
    path.read_coordinates()

    # Main loop for navigating the map
    for i in range(path.num_coords - 1):
        # Get the next position
        next_pos = path.get_next_pos(map_data, actual)

        # Check and generate files if necessary
        Info.charge_impossible(actual)
        Info.list_way(lista, actual)
        total_gold += Info.gold(actual)
        total_silver += Info.silver(actual)
        total_bronze += Info.bronze(actual)
        total_time += bateria.manage_battery_on_move(actual, next_pos)
        Info.obstacles(actual, registered_positions)

        # Update the current position
        actual[0], actual[1] = next_pos[0], next_pos[1]

    # Print the results
    print(f"Total gold areas: {total_gold}")
    print(f"Total silver areas: {total_silver}")
    print(f"Total bronze areas: {total_bronze}")
    print(f"Final total time: {total_time} seconds")

    if actual[0] == goal_position[0] and actual[1] == goal_position[1]:
        print("success")
    else:
        print("failure")

if __name__ == "__main__":
    main()
