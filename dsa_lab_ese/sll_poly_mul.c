#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff, exp;
    struct node* next;
} Node;

Node* createNode(int c, int e) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}

// Insert in decreasing exponent order (sorted insert)
Node* insertSorted(Node* head, int c, int e) {
    Node* newNode = createNode(c, e);

    if (!head || e > head->exp) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    while (temp->next && temp->next->exp >= e)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Combine like terms (Merge coefficients with same exponent)
Node* simplify(Node* head) {
    Node* temp = head;
    while (temp && temp->next) {
        if (temp->exp == temp->next->exp) {
            temp->coeff += temp->next->coeff;

            Node* del = temp->next;
            temp->next = del->next;
            free(del);
        } else {
            temp = temp->next;
        }
    }
    return head;
}

// Polynomial multiplication
Node* multiply(Node* p1, Node* p2) {
    Node* result = NULL;

    for (Node* a = p1; a; a = a->next) {
        for (Node* b = p2; b; b = b->next) {
            int c = a->coeff * b->coeff;
            int e = a->exp + b->exp;

            result = insertSorted(result, c, e);
        }
    }

    return simplify(result);
}

void printPoly(Node* head) {
    while (head) {
        printf("%dx^%d", head->coeff, head->exp);
        if (head->next) printf(" + ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *p1 = NULL, *p2 = NULL;

    // Example: 5x^3 + 2x
    p1 = insertSorted(p1, 5, 3);
    p1 = insertSorted(p1, 2, 1);

    // Example: 3x^2 + 4
    p2 = insertSorted(p2, 3, 2);
    p2 = insertSorted(p2, 4, 0);

    printf("P1 = ");
    printPoly(p1);

    printf("P2 = ");
    printPoly(p2);

    Node* prod = multiply(p1, p2);

    printf("Product = ");
    printPoly(prod);

    return 0;
}
