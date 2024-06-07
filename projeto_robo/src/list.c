#include "./include/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Insert element at the beggining
void insert_list(tList *list, const char* new_data) {
    tNode* new_node = (tNode*) malloc(sizeof(tNode));
    if (new_node == NULL) {
        printf("Error: No space left in memory.\n");
        return;
    }

    new_node->data = strdup(new_data); // Allocate memory for the string and copy data
    new_node->next = list->first_elem; // Set next of new node
    list->first_elem = new_node; // Update list external pointer to new node
}

// Remove an element of value del_data
void remove_list(tList *list, const char* del_data) {
    // Check if the list is empty
    if (list->first_elem == NULL) {
        printf("Cannot delete from an empty list.\n");
        return;
    }

    tNode* current = list->first_elem;
    tNode* prev = NULL;

    // Traverse the list to find the node to delete
    while (current != NULL && strcmp(current->data, del_data) != 0) {
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
    
        free(current->data); // Free memory allocated for the string
        free(current);  // Free memory allocated for the node
    } else {
        printf("Node with data %s not found in the list.\n", del_data);
    }
}

// Release allocated memory for the list
void free_list(tList *list) {
    tNode* current = list->first_elem;
    tNode* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp->data);  // Free memory allocated for the string
        free(temp);  // Free memory allocated for the node
    }

    list->first_elem = NULL;  // Set list pointer to NULL after freeing all nodes
}

// Print all elements of the list
void print_list(tList *list) {
    tNode* current = list->first_elem;

    printf("List elements: ");
    while (current != NULL) {
        printf("%s ", current->data);
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

