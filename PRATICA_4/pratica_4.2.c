/*

* Program: [Pilha]

* Author: [Matheus Henrique Medeiros]

* Date: [26/03/2024]

* Description: [Programa que cria, insere e deleta o último elemento de uma pilha]

* License: [CC BY]

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} tNode;

typedef struct {
    tNode* top; // Ponteiro para o topo da pilha
} tPilha;

// Inicializar a pilha
void create_pilha(tPilha *pilha) {
    pilha->top = NULL; // Inicializa o topo da pilha como NULL indicando pilha vazia
}

// Empurrar um elemento para a pilha (push)
void push(tPilha *pilha, int new_data) {
    tNode* new_node = (tNode*) malloc(sizeof(tNode));
    if (new_node == NULL) {
        printf("Erro: Sem espaço na memória.\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = pilha->top; // O próximo do novo nó aponta para o antigo topo
    pilha->top = new_node; // Atualiza o topo para o novo nó
}

// Remover o elemento do topo da pilha (pop)
int pop(tPilha *pilha) {
    if (pilha->top == NULL) {
        printf("Erro: Pilha vazia, não é possível remover elementos.\n");
    }

    tNode* temp = pilha->top; // Salva o nó do topo atual
    int popped_data = temp->data; // Salva o dado do topo atual
    pilha->top = temp->next; // Atualiza o topo para o próximo nó
    free(temp); // Libera o nó do topo atual

    return popped_data; // Retorna o dado do topo removido
}

// Liberar a memória alocada para a pilha
void free_pilha(tPilha *pilha) {
    tNode* current = pilha->top;
    tNode* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp); // Libera a memória alocada para cada nó
    }

    pilha->top = NULL; // Define o topo da pilha como NULL após liberar todos os nós
}

// Imprimir todos os elementos da pilha
void print_pilha(tPilha *pilha) {
    tNode* current = pilha->top;

    printf("Elementos da pilha: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    tPilha pilha;
    create_pilha(&pilha);
    int a,b,c,d,e, value;
    
    create_pilha(&pilha);

    printf ("Digite 1 elemento inteiro para ser adicionado ao topo pilha\n"); //Solicitar ao usuário que insira elementos
    scanf ("%d", &a);
    getchar ();
    push (&pilha, a); //Chamando a função push
    print_pilha (&pilha); //Mostrando a pilha na tela
    
    printf ("Digite 2 elementos inteiros para serem adicionados ao topo pilha\n");
    scanf ("%d", &b);
    getchar ();
    push (&pilha, b);
   
    scanf ("%d", &c);
    getchar ();
    push (&pilha, c);
    print_pilha (&pilha);
	
	pop (&pilha); //Chamando a função pop e removendo o último elemento da pilha
	print_pilha (&pilha);
	
	free_pilha (&pilha); //Desalocando memória
    return 0;
}

