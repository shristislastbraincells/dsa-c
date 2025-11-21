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

// ---- Non Recursive Inorder ----
void nonRecursiveInorder(NODE* root) {
    NODE* stack[100];
    int top = -1;
    NODE* curr = root;

    while (curr || top != -1) {
        while (curr) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

// ---- Non Recursive Preorder ----
void nonRecursivePreorder(NODE* root) {
    if (!root) return;
    NODE* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        NODE* t = stack[top--];
        printf("%d ", t->data);

        if (t->right) stack[++top] = t->right;
        if (t->left) stack[++top] = t->left;
    }
}

// ---- Non Recursive Postorder ----
void nonRecursivePostorder(NODE* root) {
    NODE *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1) {
        NODE* t = stack1[top1--];
        stack2[++top2] = t;

        if (t->left) stack1[++top1] = t->left;
        if (t->right) stack1[++top1] = t->right;
    }

    while (top2 != -1)
        printf("%d ", stack2[top2--]->data);
}

int main() {
    // Hardcoded simple tree
    NODE* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("\nNon-Recursive Inorder: ");
    nonRecursiveInorder(root);

    printf("\nNon-Recursive Preorder: ");
    nonRecursivePreorder(root);

    printf("\nNon-Recursive Postorder: ");
    nonRecursivePostorder(root);
}
