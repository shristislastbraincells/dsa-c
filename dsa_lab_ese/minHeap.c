#include <stdio.h>

void minHeapify(int a[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && a[left] < a[smallest])
        smallest = left;

    if (right < n && a[right] < a[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
        minHeapify(a, n, smallest);
    }
}

void buildMinHeap(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify(a, n, i);
}

int extractMin(int a[], int *n) {
    if (*n == 0) return -1;

    int min = a[0];
    a[0] = a[*n - 1];
    (*n)--;

    minHeapify(a, *n, 0);

    return min;
}

void heapSortMin(int a[], int n) {
    buildMinHeap(a, n);

    for (int i = n - 1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        minHeapify(a, i, 0);
    }
}

int main() {
    int a[50], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    buildMinHeap(a, n);

    printf("\nMin Heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    int size = n;
    printf("\nExtracted min: %d", extractMin(a, &size));

    printf("\nHeap after extractMin: ");
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);

    heapSortMin(a, n);

    printf("\nSorted using Min HeapSort: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
