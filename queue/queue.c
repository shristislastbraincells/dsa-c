#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int front, rear, size;
    int *arr;
};

struct Queue* createQueue(int capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->arr = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// Check if queue is full
int isFull(struct Queue* queue){
    return queue->rear == queue->size - 1;
}

// Check if queue is empty
int isEmpty(struct Queue* queue){
    return (queue->front == -1 || queue->front > queue->rear);
}

// Enqueue element at rear
void enqueue(struct Queue* queue, int element){
    if(isFull(queue)){
        printf("Queue is full\n");
        return;
    }
    if(queue->front == -1)
        queue->front = 0;
    queue->rear++;
    queue->arr[queue->rear] = element;
    printf("%d inserted into queue.\n", element);
}

// Dequeue element from front
void dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted: %d\n", queue->arr[queue->front]);
    queue->front++;
    if(queue->front > queue->rear){  // reset when queue becomes empty
        queue->front = queue->rear = -1;
    }
}

// Display queue elements
void display(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for(int i = queue->front; i <= queue->rear; i++){
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main(){
    int capacity, choice, element;
    printf("Enter size of queue: ");
    scanf("%d", &capacity);

    struct Queue* queue = createQueue(capacity);

    while(1){
        printf("\n--- Queue Menu ---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &element);
                enqueue(queue, element);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                free(queue->arr);
                free(queue);
                printf("Exiting...\n");
                return 0;  // exit properly
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
