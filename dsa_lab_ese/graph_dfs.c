#include <stdio.h>

void DFS(int adj[][50], int visited[], int v, int n) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(adj, visited, i, n);
        }
    }
}

int main() {
    int n, e, adj[50][50], visited[50];
    int i, j, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        visited[i] = 0;
        for (j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // for undirected graph
    }

    printf("Enter start vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(adj, visited, start, n);

    return 0;
}
