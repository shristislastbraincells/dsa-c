#include <stdio.h>

void maxHeapify(int a[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        maxHeapify(a, n, largest);
    }
}

void buildMaxHeap(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);
}

int extractMax(int a[], int *n) {
    if (*n == 0) return -1;

    int max = a[0];
    a[0] = a[*n - 1];
    (*n)--;

    maxHeapify(a, *n, 0);

    return max;
}

void heapSortMax(int a[], int n) {
    buildMaxHeap(a, n);

    for (int i = n - 1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        maxHeapify(a, i, 0);
    }
}

int main() {
    int a[50], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    buildMaxHeap(a, n);

    printf("\nMax Heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    int size = n;
    printf("\nExtracted max: %d", extractMax(a, &size));

    printf("\nHeap after extractMax: ");
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);

    heapSortMax(a, n);

    printf("\nSorted using Max HeapSort: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
