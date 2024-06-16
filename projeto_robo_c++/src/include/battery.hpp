#ifndef BATTERY_H
#define BATTERY_H

#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include "navigation.hpp"

#define MAX_BATTERY 4
#define RECHARGE_TIME 4
#define MOVE_TIME 2

class Battery {
public:
    Battery();
    bool is_empty() const;
    bool is_full() const;
    void push(int value);
    int pop();
    int battery_level() const;
    void recharge_battery();
    int manage_battery_on_move(int* actual, int* next_pos);

private:
    std::vector<int> stack;
    int top;
};

#endif // BATTERY_H
