#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create node
Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

// Insert at end
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

// Remove duplicates from sorted list
void removeDuplicates(Node* head) {
    Node* temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            Node* dup = temp->next;
            temp->next = temp->next->next;
            free(dup);
        } else {
            temp = temp->next;
        }
    }
}

// Display
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
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 3);

    printf("Original: ");
    display(head);

    removeDuplicates(head);

    printf("After removing duplicates: ");
    display(head);

    return 0;
}
