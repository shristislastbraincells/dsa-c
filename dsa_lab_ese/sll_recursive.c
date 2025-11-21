#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// RECURSIVE CREATE (Insert at end)
Node* create(Node* head, int x) {
    if (head == NULL) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = x;
        temp->next = NULL;
        return temp;
    }
    head->next = create(head->next, x);
    return head;
}

// RECURSIVE DISPLAY
void display(Node* head) {
    if (head == NULL) return;
    printf("%d ", head->data);
    display(head->next);
}

// RECURSIVE LENGTH
int length(Node* head) {
    if (head == NULL) return 0;
    return 1 + length(head->next);
}

// RECURSIVE REVERSE
Node* reverse(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

int main() {
    Node* head = NULL;
    int n, x;

    printf("How many elements? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &x);
        head = create(head, x);
    }

    printf("List: ");
    display(head);

    printf("\nLength: %d", length(head));

    head = reverse(head);
    printf("\nReversed: ");
    display(head);

    return 0;
}
