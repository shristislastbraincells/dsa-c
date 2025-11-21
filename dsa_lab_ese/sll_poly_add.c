#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff, exp;
    struct node* next;
} Node;

// Create a node
Node* createNode(int c, int e) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}

// Insert term at end
Node* insert(Node* head, int c, int e) {
    Node* newNode = createNode(c, e);

    if (!head) return newNode;

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Polynomial Addition
Node* addPoly(Node* p1, Node* p2) {
    Node* result = NULL;

    while (p1 && p2) {
        if (p1->exp > p2->exp) {
            result = insert(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p2->exp > p1->exp) {
            result = insert(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else { // exponents equal
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                result = insert(result, sum, p1->exp);

            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1) {
        result = insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2) {
        result = insert(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Print polynomial
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

    // Example polynomial: 5x^3 + 4x^2 + 2x^1
    p1 = insert(p1, 5, 3);
    p1 = insert(p1, 4, 2);
    p1 = insert(p1, 2, 1);

    // 3x^3 + 6x^1 + 1
    p2 = insert(p2, 3, 3);
    p2 = insert(p2, 6, 1);
    p2 = insert(p2, 1, 0);

    printf("P1 = ");
    printPoly(p1);

    printf("P2 = ");
    printPoly(p2);

    Node* sum = addPoly(p1, p2);
    printf("Sum = ");
    printPoly(sum);

    return 0;
}
