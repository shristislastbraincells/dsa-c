#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;   // top of stack

// PUSH (Insert at beginning)
void push(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = top;
    top = temp;
    printf("%d pushed\n", x);
}

// POP
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    Node* temp = top;
    printf("%d popped\n", top->data);

    top = top->next;
    free(temp);
}

// Display Top Element
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

// Display entire stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\nSTACK MENU:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); push(value); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
