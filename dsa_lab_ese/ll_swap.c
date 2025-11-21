#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int x) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = x;
    t->next = NULL;
    return t;
}

void display(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Swap nodes in pairs
Node* swapPairs(Node* head) {
    if (!head || !head->next)
        return head;

    Node* newHead = head->next;
    Node* prev = NULL;

    while (head && head->next) {
        Node* first = head;
        Node* second = head->next;

        first->next = second->next;
        second->next = first;

        if (prev) prev->next = second;

        prev = first;
        head = first->next;
    }
    return newHead;
}

int main() {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    head = swapPairs(head);
    display(head);

    return 0;
}
