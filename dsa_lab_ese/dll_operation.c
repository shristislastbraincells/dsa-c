#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

// CREATE (Insert at end)
void create(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->prev = temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }

    Node* p = head;
    while (p->next != NULL) p = p->next;

    p->next = temp;
    temp->prev = p;
}

// DISPLAY
void display() {
    Node* p = head;
    printf("List: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// INSERT at position (1-based)
void insert(int pos, int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;

    if (pos == 1) {
        temp->next = head;
        temp->prev = NULL;
        if (head) head->prev = temp;
        head = temp;
        return;
    }

    Node* p = head;
    for (int i = 1; p != NULL && i < pos - 1; i++)
        p = p->next;

    if (p == NULL) return;

    temp->next = p->next;
    temp->prev = p;

    if (p->next) p->next->prev = temp;
    p->next = temp;
}

// DELETE element (first occurrence)
void deleteVal(int x) {
    Node* p = head;

    while (p != NULL && p->data != x)
        p = p->next;

    if (p == NULL) return;

    if (p->prev) p->prev->next = p->next;
    else head = p->next;

    if (p->next) p->next->prev = p->prev;

    free(p);
}

int main() {
    int choice, x, pos;

    while (1) {
        printf("\n1.Create 2.Display 3.Insert 4.Delete 5.Exit\nEnter: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &x); create(x); break;
            case 2: display(); break;
            case 3: printf("Position: "); scanf("%d", &pos);
                    printf("Value: "); scanf("%d", &x);
                    insert(pos, x); break;
            case 4: printf("Value to delete: "); scanf("%d", &x); deleteVal(x); break;
            case 5: return 0;
        }
    }
}
