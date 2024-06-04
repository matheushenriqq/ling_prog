#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

// Definição do Nó
struct Node {
    int data;
    Node* next;
};

// Definição da Lista
class List {
public:
    // Construtor
    List();

    // Destrutor
    ~List();

    // Método para inserir um novo dado na lista
    void insert(int new_data);

    // Método para remover um dado específico da lista
    void remove(int del_data);

    // Método para liberar todos os nós da lista
    void free();

    // Método para imprimir os elementos da lista
    void print() const;

private:
    Node* first_elem; // Ponteiro para o primeiro elemento da lista
};

#endif // LIST_HPP
