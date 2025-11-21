#include <stdio.h>

#define SIZE 5

typedef struct {
    int arr[SIZE];
    int front;
    int rear;
} CircularQueue;

void init(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

int isFull(CircularQueue *q) {
    return ((q->rear + 1) % SIZE == q->front);
}

void enqueue(CircularQueue *q, int x) {
    if (isFull(q)) {
        printf("Queue is Full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % SIZE;
    }
    q->arr[q->rear] = x;
    printf("Enqueued %d\n", x);
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    }
    int val = q->arr[q->front];

    if (q->front == q->rear) {
        q->front = q->rear = -1;   // queue became empty
    } else {
        q->front = (q->front + 1) % SIZE;
    }

    return val;
}

int front(CircularQueue *q) {
    if (isEmpty(q)) return -1;
    return q->arr[q->front];
}

int rear(CircularQueue *q) {
    if (isEmpty(q)) return -1;
    return q->arr[q->rear];
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    enqueue(&q, 50);
    display(&q);

    printf("Front: %d\n", front(&q));
    printf("Rear : %d\n", rear(&q));

    return 0;
}
