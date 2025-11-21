#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* addNode(Node* head, int v) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->vertex = v;
    temp->next = head;
    return temp;
}

void BFS(Node* adj[], int visited[], int start, int n) {
    int queue[50], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        Node* temp = adj[v];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, e, i, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    Node* adj[n];
    int visited[n];

    for (i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u] = addNode(adj[u], v);
        adj[v] = addNode(adj[v], u); // undirected graph
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    BFS(adj, visited, start, n);

    return 0;
}
