#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the BST
typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} tNode;

// Function to create a new node
tNode *create_node(int key) {
    tNode *new_node = (tNode *) malloc(sizeof(tNode)); // Usando o typedef
    if (new_node == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para novo nó.\n");
        exit(EXIT_FAILURE);
    }
    new_node->key = key;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the BST
tNode *insert_node(tNode *root, int key) {
    if (root == NULL) {
        return create_node(key);
    }

    if (key < root->key) {
        root->left = insert_node(root->left, key);
    } else if (key > root->key) {
        root->right = insert_node(root->right, key);
    } else {
        fprintf(stderr, "Erro: Chave duplicada não permitida.\n");
        exit(EXIT_FAILURE);
    }

    return root;
}

// Function to find the minimum value node in a subtree
tNode *min_value_node(tNode *node) {
    tNode *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

tNode* find_k (tNode* node, int k){
	
	if (node == NULL || node->key == k){
		return node;
}
	if (node->key < k){
		return find_k (node->right, k);
	}
	return find_k (node->left, k);
}

// Function to remove a node from the BST
tNode *remove_node(tNode *root, int key) {
    if (root == NULL) {
        fprintf(stderr, "Erro: A chave não está presente na árvore.\n");
        return root;
    }

    if (key < root->key) {
        root->left = remove_node(root->left, key);
    } else if (key > root->key) {
        root->right = remove_node(root->right, key);
    } else {
        if (root->left == NULL) {
            tNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            tNode *temp = root->left;
            free(root);
            return temp;
        }

        tNode *temp = min_value_node(root->right);
        root->key = temp->key;
        root->right = remove_node(root->right, temp->key);
    }

    return root;
}

// Function to delete the BST and free memory
void delete_tree(tNode *root) {
    if (root != NULL) {
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}

// Function to print the BST in inorder traversal
void inorder_traversal(tNode *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->key);
        inorder_traversal(root->right);
    }
}

int main() {
	tNode* node = NULL;
	int x;
    tNode *root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    printf("BST in inorder traversal: ");
    inorder_traversal(root);
    printf("\n");
	printf ("Insira um valor para ser encontrado\n");
	scanf ("%d", &x);
	tNode* result = find_k(root,x);
	if (result != NULL){
		printf ("Elemento %d encontrado na arvore\n", x);
	}
	else {
		printf ("Elemento nao encontrado\n");
	}

    root = remove_node(root, 20);
    printf("BST after removing 20: ");
    inorder_traversal(root);
    printf("\n");

    delete_tree(root); // Liberando memória da árvore

    return 0;
}
