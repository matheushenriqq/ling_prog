#include <stdio.h>
#include "./include/list.h"

int main() {
    tList list = create_list();

    insert_list(&list, 10);
    insert_list(&list, 20);
    insert_list(&list, 30);

    print_list(&list);

    remove_list(&list, 20);

    print_list(&list);

    free_list(&list);

    return 0;
}
