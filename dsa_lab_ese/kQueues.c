#include <stdio.h>
#include <stdlib.h>

#define MAX 20   // total size of array
#define K 3      // number of queues

// Structure for k queues
typedef struct {
    int arr[MAX];     // main array
    int front[K];     // front indices
    int rear[K];      // rear indices
    int next[MAX];    // next free or next element
    int freeSpot;     // starting index of free list
} kQueues;

// Initialize k queues
void init(kQueues *q) {
    for (int i = 0; i < K; i++) {
        q->front[i] = -1;
        q->rear[i] = -1;
    }

    for (int i = 0; i < MAX - 1; i++)
        q->next[i] = i + 1;

    q->next[MAX - 1] = -1;
    q->freeSpot = 0;
}

// Enqueue x into queue number qn (0 to K-1)
void enqueue(kQueues *q, int x, int qn) {
    if (q->freeSpot == -1) {
        printf("Queue Overflow\n");
        return;
    }

    int index = q->freeSpot;       // take first free index
    q->freeSpot = q->next[index];  // update freeSpot

    if (q->front[qn] == -1)
        q->front[qn] = index;
    else
        q->next[q->rear[qn]] = index;

    q->next[index] = -1;
    q->rear[qn] = index;
    q->arr[index] = x;

    printf("%d enqueued in queue %d\n", x, qn);
}

// Dequeue from queue qn
int dequeue(kQueues *q, int qn) {
    if (q->front[qn] == -1) {
        printf("Queue %d is empty\n", qn);
        return -1;
    }

    int index = q->front[qn];
    q->front[qn] = q->next[index];

    // add index back to free list
    q->next[index] = q->freeSpot;
    q->freeSpot = index;

    return q->arr[index];
}

// Display one queue
void displayq(kQueues *q, int qn) {
    if (q->front[qn] == -1) {
        printf("Queue %d is empty\n", qn);
        return;
    }

    printf("Queue %d: ", qn);
    int i = q->front[qn];
    while (i != -1) {
        printf("%d ", q->arr[i]);
        i = q->next[i];
    }
    printf("\n");
}

// Display all queues
void displayAll(kQueues *q) {
    for (int i = 0; i < K; i++)
        displayq(q, i);
}

// Main function
int main() {
    kQueues q;
    init(&q);

    int choice, val, qn;

    do {
        printf("\n--- k Queues Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display One Queue\n");
        printf("4. Display All Queues\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Enter queue number (0-%d): ", K-1);
                scanf("%d", &qn);
                enqueue(&q, val, qn);
                break;

            case 2:
                printf("Enter queue number (0-%d): ", K-1);
                scanf("%d", &qn);
                val = dequeue(&q, qn);
                if (val != -1)
                    printf("Dequeued: %d\n", val);
                break;

            case 3:
                printf("Enter queue number (0-%d): ", K-1);
                scanf("%d", &qn);
                displayq(&q, qn);
                break;

            case 4:
                displayAll(&q);
                break;

            case 5:
                printf("Exiting...\n");
                break;
        }

    } while (choice != 5);

    return 0;
}
