import time
from navigation import Map, Position

MAX_BATTERY = 4
RECHARGE_TIME = 4
MOVE_TIME = 2

class Battery:
    def __init__(self):
        self.stack = [1] * MAX_BATTERY
        self.top = MAX_BATTERY - 1

    def is_empty(self):
        return self.top == -1

    def is_full(self):
        return self.top == MAX_BATTERY - 1

    def push(self, value):
        if not self.is_full():
            self.top += 1
            self.stack[self.top] = value

    def pop(self):
        if not self.is_empty():
            value = self.stack[self.top]
            self.top -= 1
            return value
        return -1  # Indicates that the battery is empty

    def battery_level(self):
        return self.top + 1

    def recharge_battery(self):
        print("Recharging battery...")
        time.sleep(RECHARGE_TIME)  # Simulate 4 seconds of charging time
        while not self.is_full():
            self.push(1)
        print(f"Battery fully recharged. Battery level: {self.battery_level()}")

    def manage_battery_on_move(self, actual, next_pos):
        mapa = Map()
        mapa.read_map_from_file()
        if not mapa.map_data:
            print("Failed to read map data")
            return -1  # Indicating error

        time_spent = 0
        y_bat = next_pos[1]
        x_bat = next_pos[0]

        if y_bat < 0 or y_bat >= mapa.sz_y or x_bat < 0 or x_bat >= mapa.sz_x:
            print("Next position out of map bounds")
            return -1  # Indicating error

        cell = mapa.map_data[y_bat][x_bat]
        level = self.battery_level()

        if cell in [255, 191, 127, 63]:  # Navigable areas
            if level > 1:
                self.pop()
                actual[0], actual[1] = x_bat, y_bat
                time_spent += MOVE_TIME
                print("2 seconds for move")
                time.sleep(MOVE_TIME)
                print(f"Moved to ({actual[0]}, {actual[1]}), Battery: {self.battery_level()}")

                if level - 1 < 2:
                    print(f"Battery low. Charging at ({actual[0]}, {actual[1]})")
                    self.recharge_battery()
                    with open("./data/charging.txt", "a") as file:
                        file.write(f"Charge at ({x_bat}, {y_bat})\n")
                    time_spent += RECHARGE_TIME
            else:
                print("Not enough battery to move")
        elif cell == 1:  # Area with impossibility of charge
            if level > 2:
                self.pop()
                actual[0], actual[1] = x_bat, y_bat
                time_spent += MOVE_TIME
                print("2 seconds for move")
                time.sleep(MOVE_TIME)
                print(f"Moved to ({actual[0]}, {actual[1]}), Battery: {self.battery_level()}")
            else:
                print(f"Battery too low to move to an area with impossibility of charge. Charging at ({actual[0]}, {actual[1]})")
                self.recharge_battery()
                with open("./data/charging.txt", "a") as file:
                    file.write(f"Charge at ({actual[0]}, {actual[1]})\n")
                time_spent += RECHARGE_TIME
                self.pop()
                actual[0], actual[1] = x_bat, y_bat
                time_spent += MOVE_TIME
                print("2 seconds for move")
                time.sleep(MOVE_TIME)
                print(f"Moved to ({actual[0]}, {actual[1]}), Battery: {self.battery_level()}")

        return time_spent
