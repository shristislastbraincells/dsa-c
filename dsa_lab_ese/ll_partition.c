#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void insertEnd(Node** head, int data) {
    Node* n = createNode(data);

    if (*head == NULL) {
        *head = n;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
}

// Partition list around x
Node* partition(Node* head, int x) {
    Node *beforeStart = NULL, *beforeEnd = NULL;
    Node *afterStart = NULL, *afterEnd = NULL;

    while (head != NULL) {
        Node* next = head->next;
        head->next = NULL;

        if (head->data < x) {
            // Add to before list
            if (beforeStart == NULL) {
                beforeStart = beforeEnd = head;
            } else {
                beforeEnd->next = head;
                beforeEnd = head;
            }
        } else {
            // Add to after list
            if (afterStart == NULL) {
                afterStart = afterEnd = head;
            } else {
                afterEnd->next = head;
                afterEnd = head;
            }
        }

        head = next;
    }

    if (beforeStart == NULL) 
        return afterStart;

    beforeEnd->next = afterStart;
    return beforeStart;
}

void display(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 5);
    insertEnd(&head, 3);
    insertEnd(&head, 2);
    insertEnd(&head, 4);
    insertEnd(&head, 2);

    printf("Original: ");
    display(head);

    head = partition(head, 3);

    printf("Partitioned around 3: ");
    display(head);

    return 0;
}
