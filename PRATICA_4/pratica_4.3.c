/*

* Program: [Lista]

* Author: [Matheus Henrique Medeiros]

* Date: [26/03/2024]

* Description: [Programa que cria, insere e deleta o elemento final de uma fila]

* License: [CC BY]

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} tNode;

typedef struct {
    tNode* front; // Ponteiro para o início da fila
    tNode* rear;  // Ponteiro para o final da fila
} tFila;

// Inicializar a fila
void create_fila(tFila *fila) {
    fila->front = NULL; // Inicializa o início da fila como NULL (fila vazia)
    fila->rear = NULL;  // Inicializa o final da fila como NULL (fila vazia)
}

// Inserir um elemento no final da fila
void insert_rear(tFila *fila, int new_data) {
    tNode* new_node = (tNode*) malloc(sizeof(tNode));
    if (new_node == NULL) {
        printf("Erro: Sem espaço na memória.\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = NULL; // O próximo do novo nó é NULL, pois ele será o último

    // Se a fila estiver vazia, tanto o início quanto o final apontam para o novo nó
    if (fila->front == NULL) {
        fila->front = new_node;
    } else {
        fila->rear->next = new_node; // O próximo do antigo último nó aponta para o novo nó
    }

    fila->rear = new_node; // Atualiza o final da fila para o novo nó
}

// Remover e retornar o elemento do início da fila
int remove_front(tFila *fila) {
    if (fila->front == NULL) {
        printf("Erro: Fila vazia, não é possível remover elementos.\n");
        return -1; // Valor de erro
    }

    tNode* temp = fila->front; // Salva o nó do início atual
    int removed_data = temp->data; // Salva o dado do início atual

    fila->front = fila->front->next; // Atualiza o início para o próximo nó
    free(temp); // Libera o nó do início atual

    // Se o início da fila se tornou NULL, significa que a fila está vazia, então o final também deve ser atualizado para NULL
    if (fila->front == NULL) {
        fila->rear = NULL;
    }

    return removed_data; // Retorna o dado do início removido
}

// Liberar a memória alocada para a fila
void free_fila(tFila *fila) {
    tNode* current = fila->front;
    tNode* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp); // Libera a memória alocada para cada nó
    }

    fila->front = NULL; // Define o início da fila como NULL após liberar todos os nós
    fila->rear = NULL;  // Define o final da fila como NULL após liberar todos os nós
}

// Imprimir todos os elementos da fila
void print_fila(tFila *fila) {
    tNode* current = fila->front;

    printf("Elementos da fila: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    tFila fila;
    create_fila(&fila);
    int a,b,c;
	
    printf ("Digite 3 elementos inteiros para serem adicionados ao final da fila\n"); //Solicitar ao usuário que insira elementos
    scanf ("%d", &a);
    getchar ();
    insert_rear(&fila, a); //Chamando a função insert para adicionar o elemento ao final da fila

    scanf ("%d", &b);
    getchar ();
    insert_rear(&fila, b); //Chamando a função insert para adicionar o elemento ao final da fila

    scanf ("%d", &c);
    getchar ();
    insert_rear(&fila, c); //Chamando a função insert para adicionar o elemento ao final da fila
    
	print_fila(&fila); //Mostrando a fila 
	
	remove_front (&fila); //Removendo o elemento do inicio da fila
    print_fila(&fila);
    
    free_fila (&fila); //Desalocando memória
    

    return 0;
}


