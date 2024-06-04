#include "./include/list.h"
#include <stdio.h>
#include <stdlib.h>

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

void remove_list(tList *list, int del_data) {
    if (list->first_elem == NULL) {
        printf("Cannot delete from an empty list.\n");
        return;
    }

    tNode* current = list->first_elem;
    tNode* prev = NULL;

    while (current != NULL && current->data != del_data) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            list->first_elem = current->next;  
        } else {
            prev->next = current->next;  
        }
    
        free(current);  
    } else {
        printf("Node with data %d not found in the list.\n", del_data);
    }
}

void free_list(tList *list) {
    tNode* current = list->first_elem;
    tNode* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);  
    }

    list->first_elem = NULL;  
}

void print_list(tList *list) {
    tNode* current = list->first_elem;

    printf("List elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

tList create_list() {
    tList list;
    list.first_elem = NULL;  
    return list;
}
