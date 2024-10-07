#include <stdio.h>

#define MAX 100
#define INF 999999

int n, e; // Number of nodes and edges
int graph[MAX][MAX], visited[MAX], bestRoute[MAX], currentRoute[MAX];
int min = INF; 

void tsp(int pos, int visitedCount, int cost, int start) {
    
    if (visitedCount == n && graph[pos][start]) {
        cost += graph[pos][start]; // Add cost to return to start

        if (cost < min) { // Update minimum cost
            min = cost;

            for (int i = 0; i < n; i++) {
                bestRoute[i] = currentRoute[i];
            }
            bestRoute[n] = start; // Connect starting point to route
        }

        return;
    }

    // Explore each node
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = 1; // Mark node as visited
            currentRoute[visitedCount] = i; // Store current node

            tsp(i, visitedCount + 1, cost + graph[pos][i], start);
            visited[i] = 0;
        }
    }
}

void findTSP(int start) {
    visited[start] = 1; // Start from the initial node
    currentRoute[0] = start;
    tsp(start, 1, 0, start); // Start the TSP recursion

    // Output
    printf("Cost: %d\n", min);
    printf("Route: ");
    for (int i = 0; i < n; i++) {
        printf("%d", bestRoute[i]);

        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &e);

    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0;

            } else graph[i][j] = INF;
        }
    }

    // Read edges and costs
    for (int i = 0; i < e; i++) {
        int edge, u, v, cost;
        scanf("%d %d %d %d", &edge, &u, &v, &cost);

        graph[u - 1][v - 1] = cost;
        graph[v - 1][u - 1] = cost;
    }

    // Starting point
    int start;
    scanf("%d", &start);

    findTSP(start - 1);


    return 0;
}
