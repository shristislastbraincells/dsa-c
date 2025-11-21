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

int search(int arr[], int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (arr[i] == val) return i;
    return -1;
}

NODE* build(int in[], int pre[], int start, int end, int *preIndex) {
    if (start > end) return NULL;

    NODE* root = newNode(pre[*preIndex]);
    (*preIndex)++;

    if (start == end) return root;

    int pos = search(in, start, end, root->data);

    root->left = build(in, pre, start, pos - 1, preIndex);
    root->right = build(in, pre, pos + 1, end, preIndex);

    return root;
}

void postorder(NODE* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int inorder[] = {4, 2, 5, 1, 3};
    int preorder[] = {1, 2, 4, 5, 3};
    int n = 5;

    int preIndex = 0;
    NODE* root = build(inorder, preorder, 0, n - 1, &preIndex);

    printf("Postorder: ");
    postorder(root);
}
