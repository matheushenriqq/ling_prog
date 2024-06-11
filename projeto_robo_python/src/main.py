# main.py
from robot_functions import navigation as nav

if __name__ == "__main__":
    map_obj = nav.Map()
    map_data = map_obj.get_map()

    actual = [0, 0]
    next_pos = [-1, -1]

    path_obj = nav.Path()
    path_obj.read_coordinates()  # Leitura das coordenadas de uma vez

    while True:
        next_pos = path_obj.get_next_pos(map_data, actual)

        if next_pos[0] == -1 and next_pos[1] == -1:
            print("Reached the end of the path or an error occurred.")
            break

        print(f"Current Position: ({actual[0]},{actual[1]}) -> Next Position: ({next_pos[0]},{next_pos[1]})")

        # Atualizar a posição atual para a próxima posição
        actual[0] = next_pos[0]
        actual[1] = next_pos[1]

        # Exemplo de atualização das coordenadas
        new_path = [nav.Position(1, 1), nav.Position(2, 2), nav.Position(3, 3)]  # Exemplo de novas coordenadas
        path_obj.update_coordinates(new_path)

    print("Final Position:", actual)
