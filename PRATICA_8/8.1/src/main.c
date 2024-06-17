/*

Program: Experimento 8.1

Author: Matheus Henrique Medeiros

Date: 10/06/2024

Description: Monte o seu próprio projeto na linguagem C para os arquivos relacionados a definição de uma lista

License: [CC BY]

*/

#include <stdio.h>
#include "./include/list.h"

int main() {
    tList list = create_list();

    insert_list(&list, 10); // Função para inserir um dado na lista.
    insert_list(&list, 20);
    insert_list(&list, 30);

    print_list(&list); // Função para imprimir a lista

    remove_list(&list, 20); // Função para remover o elemento 20 da lista

    print_list(&list);

    free_list(&list); // Liberar memória alocada

    return 0;
}