#include "./include/list.hpp"
#include <iostream>

int main() {
    List list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.print(); // Output: List elements: 30 20 10

    list.remove(20);
    list.print(); // Output: List elements: 30 10

    list.remove(40); // Output: Node with data 40 not found in the list.

    list.free();
    list.print(); // Output: List elements: 

    return 0;
}