#ifndef LIST.H
#define LIST.H

typedef struct node {
    char data;
    struct node* next;
} tNode;

typedef struct list {
    tNode* first_elem;
} tList;

void insert_list(tList *list, const char* new_data);
void remove_list(tList *list, const char* new_data);
void free_list(tList *list);
void print_list(tList *list);
tList create_list();

#endif /* NAVIGATION_H */
