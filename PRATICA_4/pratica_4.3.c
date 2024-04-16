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
    tNode* front; // Ponteiro para o in�cio da fila
    tNode* rear;  // Ponteiro para o final da fila
} tFila;

// Inicializar a fila
void create_fila(tFila *fila) {
    fila->front = NULL; // Inicializa o in�cio da fila como NULL (fila vazia)
    fila->rear = NULL;  // Inicializa o final da fila como NULL (fila vazia)
}

// Inserir um elemento no final da fila
void insert_rear(tFila *fila, int new_data) {
    tNode* new_node = (tNode*) malloc(sizeof(tNode));
    if (new_node == NULL) {
        printf("Erro: Sem espa�o na mem�ria.\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = NULL; // O pr�ximo do novo n� � NULL, pois ele ser� o �ltimo

    // Se a fila estiver vazia, tanto o in�cio quanto o final apontam para o novo n�
    if (fila->front == NULL) {
        fila->front = new_node;
    } else {
        fila->rear->next = new_node; // O pr�ximo do antigo �ltimo n� aponta para o novo n�
    }

    fila->rear = new_node; // Atualiza o final da fila para o novo n�
}

// Remover e retornar o elemento do in�cio da fila
int remove_front(tFila *fila) {
    if (fila->front == NULL) {
        printf("Erro: Fila vazia, n�o � poss�vel remover elementos.\n");
        return -1; // Valor de erro
    }

    tNode* temp = fila->front; // Salva o n� do in�cio atual
    int removed_data = temp->data; // Salva o dado do in�cio atual

    fila->front = fila->front->next; // Atualiza o in�cio para o pr�ximo n�
    free(temp); // Libera o n� do in�cio atual

    // Se o in�cio da fila se tornou NULL, significa que a fila est� vazia, ent�o o final tamb�m deve ser atualizado para NULL
    if (fila->front == NULL) {
        fila->rear = NULL;
    }

    return removed_data; // Retorna o dado do in�cio removido
}

// Liberar a mem�ria alocada para a fila
void free_fila(tFila *fila) {
    tNode* current = fila->front;
    tNode* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp); // Libera a mem�ria alocada para cada n�
    }

    fila->front = NULL; // Define o in�cio da fila como NULL ap�s liberar todos os n�s
    fila->rear = NULL;  // Define o final da fila como NULL ap�s liberar todos os n�s
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
	
    printf ("Digite 3 elementos inteiros para serem adicionados ao final da fila\n"); //Solicitar ao usu�rio que insira elementos
    scanf ("%d", &a);
    getchar ();
    insert_rear(&fila, a); //Chamando a fun��o insert para adicionar o elemento ao final da fila

    scanf ("%d", &b);
    getchar ();
    insert_rear(&fila, b); //Chamando a fun��o insert para adicionar o elemento ao final da fila

    scanf ("%d", &c);
    getchar ();
    insert_rear(&fila, c); //Chamando a fun��o insert para adicionar o elemento ao final da fila
    
	print_fila(&fila); //Mostrando a fila 
	
	remove_front (&fila); //Removendo o elemento do inicio da fila
    print_fila(&fila);
    
    free_fila (&fila); //Desalocando mem�ria
    

    return 0;
}


