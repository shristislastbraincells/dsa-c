#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int front,rear,size;
    int *arr;
};
struct Queue *createQueue(int capacity){
    struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
    queue->size=capacity;
    queue->front=-1;
    queue->rear=-1;
    queue->arr=(int*)malloc(capacity*sizeof(int));
    return queue;
}
int isFull(struct Queue* queue){
    return ((queue->rear+1)%queue->size)==queue->front;
}
int isEmpty(struct Queue* queue){
    return queue->front==-1;
}
void enqueue(struct Queue* queue,int element){
    if(isFull(queue)){
        printf("Queue is full");
        return;
    }
    if(isEmpty(queue)){
        queue->front=0;
    }
    queue->rear=(queue->rear+1)%queue->size;
    queue->arr[queue->rear]=element;
}
void dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is empty");
        return;
    }
    if(queue->front==queue->rear){
        queue->front=-1;
        queue->rear=-1;
    }
    else{
        queue->front=(queue->front+1)%queue->size;
    }
}
void display(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is empty");
        return;
    }
    printf("Queue elements:");
    int i=queue->front;
    while(1){
        printf("[%d]:%d",i,queue->arr[i]);
        if(i==queue->rear)
            break;
        i=(i+1)%queue->size;
    }
    printf("\n");
}
int main() {
    int capacity, choice, value;

    printf("Enter the size of the circular queue: ");
    scanf("%d", &capacity);
    struct Queue* queue = createQueue(capacity);
    while (1) {
    printf("\n--- Circular Queue Menu ---\n");
    printf("1. Insert (Enqueue)\n");
    printf("2. Delete (Dequeue)\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(queue, value);
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
            exit(0);
        default:
        printf("Invalid choice! Try again.\n");
    }
 }
 return 0;
}
