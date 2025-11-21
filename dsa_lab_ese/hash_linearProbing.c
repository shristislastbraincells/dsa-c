#include <stdio.h>

#define SIZE 10

void init(int hash[]) {
    for (int i = 0; i < SIZE; i++)
        hash[i] = -1;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int hash[], int key) {
    int index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;
        if (hash[newIndex] == -1) {
            hash[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
    }
    printf("Hash table is full\n");
}

int search(int hash[], int key) {
    int index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if (hash[newIndex] == key)
            return newIndex;

        if (hash[newIndex] == -1)
            return -1;
    }
    return -1;
}

void display(int hash[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d : %d\n", i, hash[i]);
}

int main() {
    int hash[SIZE];
    init(hash);

    int choice, key;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            insert(hash, key);
            break;

        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            int pos;
            pos = search(hash, key);
            if (pos != -1)
                printf("Key found at index %d\n", pos);
            else
                printf("Key not found\n");
            break;

        case 3:
            display(hash);
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
