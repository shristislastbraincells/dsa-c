#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} NODE;

NODE* newNode(int x) {
    NODE* t = (NODE*)malloc(sizeof(NODE));
    t->data = x; t->left = t->right = NULL;
    return t;
}

int isEqual(NODE* a, NODE* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;

    return (a->data == b->data &&
            isEqual(a->left, b->left) &&
            isEqual(a->right, b->right));
}

NODE* mirror(NODE* root) {
    if (!root) return NULL;

    NODE* L = mirror(root->left);
    NODE* R = mirror(root->right);

    root->left = R;
    root->right = L;

    return root;
}

void inorder(NODE* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    NODE* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);

    NODE* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);

    printf("Trees Equal? %d\n", isEqual(root1, root2));

    printf("Original inorder: ");
    inorder(root1);

    mirror(root1);
    printf("\nMirror inorder: ");
    inorder(root1);
}
