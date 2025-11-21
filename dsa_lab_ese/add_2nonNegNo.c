#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert at beginning (useful for reversing)
Node* push(Node* head, int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = head;
    return temp;
}

// Reverse a linked list
Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Add two reversed linked lists
Node* addLists(Node* a, Node* b) {
    Node* result = NULL;
    int carry = 0;

    while (a || b || carry) {
        int sum = carry;

        if (a) { sum += a->data; a = a->next; }
        if (b) { sum += b->data; b = b->next; }

        carry = sum / 10;
        sum = sum % 10;

        result = push(result, sum);  // insert at head for correct order
    }
    return result;
}

void display(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Example input
    Node *A = NULL, *B = NULL;

    // 7→2→3→3
    A = push(A, 3);
    A = push(A, 3);
    A = push(A, 2);
    A = push(A, 7);

    // 5→7→4
    B = push(B, 4);
    B = push(B, 7);
    B = push(B, 5);

    A = reverse(A);
    B = reverse(B);

    Node* sum = addLists(A, B);
    sum = reverse(sum);

    display(sum);

    return 0;
}
