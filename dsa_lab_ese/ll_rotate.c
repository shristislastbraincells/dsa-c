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

Node* rotate(Node* head, int k) {
    if (!head || k == 0) return head;

    // Compute length
    Node* temp = head;
    int len = 1;
    while (temp->next) {
        len++;
        temp = temp->next;
    }

    k = k % len; // handle large k
    if (k == 0) return head;

    temp->next = head;  // make circular

    // Move to (len-k)-th node
    int steps = len - k;
    Node* p = head;
    for (int i = 1; i < steps; i++)
        p = p->next;

    head = p->next;   // new head
    p->next = NULL;   // break circle

    return head;
}

int main() {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    head = rotate(head, 2);
    display(head);
    return 0;
}
