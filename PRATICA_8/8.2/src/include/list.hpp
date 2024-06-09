#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

// Node definition
struct Node {
    int data;
    Node* next;
};

// List definition
class List {
public:
    // Constructor
    List();

    // Destructor
    ~List();

    // Method to insert a new data into the list
    void insert(int new_data);

    // Method to remove a specific data from the list
    void remove(int del_data);

    // Method to print the elements of the list
    void print() const;

private:
    Node* first_elem; // Pointer to the first element of the list
    void free(); // Method to free all nodes of the list (private)
};

#endif // LIST_HPP
