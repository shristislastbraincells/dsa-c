#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *front = NULL, *rear = NULL;

// ENQUEUE (Insert at end)
void enqueue(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {  
        front = rear = temp; // First element
    } else {
        rear->next = temp;
        rear = temp;
    }
    printf("%d enqueued\n", x);
}

// DEQUEUE (Remove from front)
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    Node* temp = front;
    printf("%d dequeued\n", front->data);

    front = front->next;

    if (front == NULL)  // queue becomes empty
        rear = NULL;

    free(temp);
}

// Display queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// FRONT element
void frontElement() {
    if (front == NULL) printf("Queue empty\n");
    else printf("Front: %d\n", front->data);
}

// REAR element
void rearElement() {
    if (rear == NULL) printf("Queue empty\n");
    else printf("Rear: %d\n", rear->data);
}

int main() {
    int choice, value;

    do {
        printf("\nQUEUE MENU:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Front\n5. Rear\n6. Exit\nEnter: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); enqueue(value); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: frontElement(); break;
            case 5: rearElement(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
