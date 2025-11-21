#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} NODE;

NODE* create() {
    int x;
    printf("Enter value (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1) return NULL;

    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = x;

    printf("Enter left child of %d\n", x);
    temp->left = create();

    printf("Enter right child of %d\n", x);
    temp->right = create();

    return temp;
}

void inorder(NODE* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int height(NODE* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

// Level-order uses queue
typedef struct {
    NODE* arr[100];
    int front, rear;
} QUEUE;

void enqueue(QUEUE *q, NODE* x) { q->arr[++q->rear] = x; }
NODE* dequeue(QUEUE *q) { return q->arr[++q->front]; }
int isEmpty(QUEUE *q) { return q->front == q->rear; }

void levelOrder(NODE* root) {
    if (!root) return;

    QUEUE q = { .front = -1, .rear = -1 };
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        NODE* temp = dequeue(&q);
        printf("%d ", temp->data);

        if (temp->left) enqueue(&q, temp->left);
        if (temp->right) enqueue(&q, temp->right);
    }
}

int countLeaves(NODE* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int countNonLeaves(NODE* root) {
    if (!root || (!root->left && !root->right)) return 0;
    return 1 + countNonLeaves(root->left) + countNonLeaves(root->right);
}

int countNodes(NODE* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    NODE* root = create();

    printf("\nInorder: "); inorder(root);
    printf("\nHeight: %d", height(root));
    printf("\nLevel Order: "); levelOrder(root);

    printf("\nLeaf Nodes: %d", countLeaves(root));
    printf("\nNon-Leaf Nodes: %d", countNonLeaves(root));
    printf("\nTotal Nodes: %d", countNodes(root));
}
