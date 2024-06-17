import os
from navigation import Map, Position, Path
from list_module import tList, insert_list, tNode

class Info:
    @staticmethod
    def clear_file(filepath):
        with open(filepath, 'w'):
            pass
        print(f"File {filepath} cleared.")

    @staticmethod
    def charge_impossible(actual):
        mapa = Map()
        mapa.read_map_from_file()
        y = actual[1]
        x = actual[0]

        with open("./data/charge_impossible.txt", "a") as file:
            directions = [
                (0, 1), (1, 1), (-1, 1),
                (1, 0), (-1, 0)
            ]

            for dx, dy in directions:
                new_x = x + dx
                new_y = y + dy
                if 0 <= new_x < mapa.sz_x and 0 <= new_y < mapa.sz_y:
                    color = mapa.map_data[new_y][new_x]
                    if color == 1:
                        print(f"Checking sun at position ({new_x}, {new_y}): {color}")
                        file.write(f"impossibility of loading found at position ({new_x}, {new_y})\nImpossible to charge\n")
                        print(f"impossibility of loading found at position ({new_x}, {new_y}) and written to file.")

    @staticmethod
    def list_way(list_obj, actual):
        mapa = Map()
        mapa.read_map_from_file()
        y = actual[1]
        x = actual[0]

        color = mapa.map_data[y][x]
        if color == 255:
            insert_list(list_obj, "free_2_go")
        elif color == 191:
            insert_list(list_obj, "gold")
        elif color == 127:
            insert_list(list_obj, "silver")
        elif color == 63:
            insert_list(list_obj, "bronze")
        elif color == 1:
            insert_list(list_obj, "charge_impossible")

        current = list_obj.first_elem
        with open("./data/list_way.txt", "w") as file:
            file.write("List elements:\n")
            while current:
                file.write(f"{current.data}\n")
                current = current.next

    @staticmethod
    def gold(actual):
        mapa = Map()
        mapa.read_map_from_file()
        y = actual[1]
        x = actual[0]
        count = 0

        if mapa.map_data[y][x] == 191:
            with open("./data/gold.txt", "a") as file:
                file.write(f"Gold found at position ({x}, {y})\ngold\n")
            print(f"Gold found at position ({x}, {y}) and written to file.")
            count += 1

        return count

    @staticmethod
    def silver(actual):
        mapa = Map()
        mapa.read_map_from_file()
        x = actual[0]
        y = actual[1]
        count = 0

        if mapa.map_data[y][x] == 127:
            with open("./data/silver.txt", "a") as file:
                file.write(f"Silver found at position ({x}, {y})\nsilver\n")
            print(f"Silver found at position ({x}, {y}) and written to file.")
            count += 1

        return count

    @staticmethod
    def bronze(actual):
        mapa = Map()
        mapa.read_map_from_file()
        x = actual[0]
        y = actual[1]
        count = 0

        if mapa.map_data[y][x] == 63:
            with open("./data/bronze.txt", "a") as file:
                file.write(f"Bronze found at position ({x}, {y})\nbronze\n")
            print(f"Bronze found at position ({x}, {y}) and written to file.")
            count += 1

        return count

    @staticmethod
    def obstacles(actual, registered_positions):
        mapa = Map()
        mapa.read_map_from_file()
        y = actual[1]
        x = actual[0]
        count = 0

        with open("./data/obstacles.txt", "a") as file:
            directions = [
                (0, 1), (0, -1), (1, 0), (-1, 0),
                (1, 1), (-1, -1), (1, -1), (-1, 1)
            ]

            for dx, dy in directions:
                new_x = x + dx
                new_y = y + dy
                if 0 <= new_x < mapa.sz_x and 0 <= new_y < mapa.sz_y:
                    color = mapa.map_data[new_y][new_x]
                    if color == 0 and not Info.position_exists(registered_positions, new_x, new_y):
                        registered_positions.append(Position(new_x, new_y))
                        count += 1
                        print(f"obstacle_found ({new_x}, {new_y})")
                        file.write(f"Obstacle (color 0) found at position ({new_x}, {new_y})\n")

        return count

    @staticmethod
    def position_exists(positions, x, y):
        return any(pos.x == x and pos.y == y for pos in positions)
