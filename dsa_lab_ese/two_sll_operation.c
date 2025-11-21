#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// INSERT SORTED
Node* insertSorted(Node* head, int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL || x < head->data) {
        temp->next = head;
        return temp;
    }

    Node* p = head;
    while (p->next != NULL && p->next->data < x)
        p = p->next;

    temp->next = p->next;
    p->next = temp;
    return head;
}

// DISPLAY
void display(Node* head) {
    Node* p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// A) MERGE TWO SORTED LISTS
Node* merge(Node* A, Node* B) {
    if (A == NULL) return B;
    if (B == NULL) return A;

    Node* result = NULL;

    if (A->data < B->data) {
        result = A;
        result->next = merge(A->next, B);
    } else {
        result = B;
        result->next = merge(A, B->next);
    }

    return result;
}

// B) CHECK IF EQUAL
int equal(Node* A, Node* B) {
    while (A && B) {
        if (A->data != B->data) return 0;
        A = A->next;
        B = B->next;
    }
    return (A == NULL && B == NULL);
}

// C) COPY A LINKED LIST
Node* copy(Node* head) {
    if (head == NULL) return NULL;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = head->data;
    newNode->next = copy(head->next);
    return newNode;
}

int main() {
    Node *A = NULL, *B = NULL;

    // Example input
    A = insertSorted(A, 1);
    A = insertSorted(A, 3);
    A = insertSorted(A, 5);

    B = insertSorted(B, 2);
    B = insertSorted(B, 4);
    B = insertSorted(B, 6);

    printf("A: "); display(A);
    printf("B: "); display(B);

    // Merge
    Node* M = merge(A, B);
    printf("Merged: ");
    display(M);

    // Copy
    Node* C = copy(M);
    printf("Copy: ");
    display(C);

    // Equal check
    printf("Equal? %d", equal(M, C));

    return 0;
}
