#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} NODE;

// Create a new node
NODE* createNode(int x) {
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into BST
NODE* insert(NODE* root, int x) {
    if (root == NULL) return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

// Traversals
void inorder(NODE* root) {       
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(NODE* root) {      
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NODE* root) {     
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Descending = Reverse Inorder
void descending(NODE* root) {
    if (!root) return;
    descending(root->right);
    printf("%d ", root->data);
    descending(root->left);
}

int main() {
    NODE *root = NULL;
    int arr[] = {30, 15, 40, 10, 20, 35, 50};

    for (int i = 0; i < 7; i++)
        root = insert(root, arr[i]);

    printf("Inorder: "); inorder(root);
    printf("\nPreorder: "); preorder(root);
    printf("\nPostorder: "); postorder(root);
    printf("\nDescending: "); descending(root);
}
