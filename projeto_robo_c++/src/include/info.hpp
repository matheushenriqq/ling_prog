#ifndef INFO_H
#define INFO_H

#include "navigation.hpp"
#include "list.hpp"
#include <vector>
#include <string>

class Info {
public:
    static void clear_file(const std::string &filepath);
    static void charge_impossible(int actual[2]);
    static void list_way(tList &list, int actual[2]);
    static int gold(int actual[2]);
    static int silver(int actual[2]);
    static int bronze(int actual[2]);
    static int obstacles(int actual[2], std::vector<Position> &registered_positions);
    static bool position_exists(const std::vector<Position> &positions, int x, int y);
};

#endif // INFO_H
