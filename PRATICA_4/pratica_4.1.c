/*

* Program: [Lista]

* Author: [Matheus Henrique Medeiros]

* Date: [26/03/2024]

* Description: [Programa que cria, insere e deleta elementos de uma lista]

* License: [CC BY]

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} tNode;

typedef struct {
    tNode* first_elem;
} tList;

// Insert element at the beggining
void insert_list(tList *list, int new_data) {
    tNode* new_node = (tNode*) malloc(sizeof(tNode));
    if (new_node == NULL) {
        printf("Error: No space left in memory.\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = list->first_elem; // Set next of new node
    list->first_elem = new_node; // Update list external pointer to new node
}

// Remove an element of value del_data
void remove_list(tList *list, int del_data) {
    // Check if the list is empty
    if (list->first_elem == NULL) {
        printf("Cannot delete from an empty list.\n");
        return;
    }

    tNode* current = list->first_elem;
    tNode* prev = NULL;

    // Traverse the list to find the node to delete
    while (current != NULL && current->data != del_data) {
        prev = current;
        current = current->next;
    }

    // If the node to delete is found
    if (current != NULL) {
        // If the node to delete is the first node
        if (prev == NULL) {
            list->first_elem = current->next;  // Update list pointer to skip the first node
        } else {
            prev->next = current->next;  // Link the previous node to the next of the current node
        }
    
        free(current);  // Free memory allocated for the node
    } else {
        printf("Node with data %d not found in the list.\n", del_data);
    }
}

// Release allocated memory for the list
void free_list(tList *list) {
    tNode* current = list->first_elem;
    tNode* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);  // Free memory allocated for each node
    }

    list->first_elem = NULL;  // Set list pointer to NULL after freeing all nodes
}

// Print all elements of the list
void print_list(tList *list) {
    tNode* current = list->first_elem;

    printf("List elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}



// List constructor
tList create_list() {
    tList list;
    list.first_elem = NULL;  // Initialize the list with NULL pointer
    return list;
}

int main(){
    
    tList list = create_list();
    int a,b,c,d,e, value;
    
    insert_list(&list, 10);
    insert_list(&list, 20);
    insert_list(&list, 30);
    
    printf ("Digite 5 elementos inteiros para serem adicionado a lista\n"); //Solicitação ao usuário que adicione 5 elementos a lista
    scanf ("%d", &a);
    scanf ("%d", &b);
    scanf ("%d", &c);
    scanf ("%d", &d);
    scanf ("%d", &e);
    getchar();
    
    insert_list(&list, a);// Chamando a função para inserir elementos na lista
    insert_list(&list, b);
    insert_list(&list, c);
    insert_list(&list, d);
    insert_list(&list, e);
    
    print_list(&list); //Chamando a função para mostrar a lista

    free_list(&list); // Desalocando memória

    return 0;
}
