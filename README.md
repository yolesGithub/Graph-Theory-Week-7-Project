# Graph Theory Week 7 Assignment

| Name  | NRP |
| ------------- | ------------- |
| Muh. Yusuf Haidar Khairullah  | 5111942000022  |
| Haidar Daffa Firzatullah  | 5025231071  |

## Traveling Salesman Problem
### Problem Description

The Travelling Salesman Problem (TSP) is a combinatorial optimization problem. Given a set of cities and the distances between each pair of cities, the task is to find the shortest possible tour that visits each city exactly once and returns to the starting city.

### Code Explanation

'''
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
'''
This function implements the core logic of the Traveling Salesman Problem using recursion and backtracking. It explores all possible paths from the current position (pos) and keeps track of the cost (cost) of visiting nodes

'''
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
'''
This function initiates the algorithm from a given start node by marking the start as visited and calling the recursive tsp function. After the recursion finishes, it prints the minimum cost and the best route found.



## Chinese Postman Problem
### Problem Description

The Chinese Postman Problem aims to find the shortest closed path or circuit that visits every edge of a graph at least once. This is particularly useful in logistics and postal routing scenarios.

### Code Explanation

'''
// Function to initialize the graph with no edges
void initializeGraph() {
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            if (i == j)
                graph[i][j] = 0; // No cost for self-loop
            else
                graph[i][j] = INF; // No edge between i and j
        }
    }
}
'''
This function initializes the graph by setting the diagonal to 0 (cost of self-loops) and all other edges to INF (no direct edges between nodes).

'''
// Function to print the Eulerian circuit
void printCircuit(int start, int cost) {
    printf("Cost: %d\n", cost);
    printf("Route: ");
    
    // Here you can implement Hierholzer's algorithm to find the Eulerian Circuit
    // This is just a placeholder for the demonstration:
    printf("0, 1, 3, 2, 3\n");  // Replace this with your route calculation
}
'''
Prints the Eulerian circuit and its total cost. The function currently contains a placeholder for the Eulerian circuit calculation (Hierholzer's algorithm can be used here).

'''
// Check if the degree of all vertices is even
bool isEulerian() {
    int degree[MAX_NODES] = {0};

    // Count the degree of each vertex
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != INF && graph[i][j] != 0)
                degree[i]++;
        }
    }

    // Check if all vertices have even degree
    for (int i = 0; i < n; i++) {
        if (degree[i] % 2 != 0)
            return false;
    }
    return true;
}
'''
Checks whether the graph is Eulerian by ensuring all vertices have even degrees. The function returns true if the graph is Eulerian and false otherwise.

'''
// Floyd-Warshall algorithm to find the shortest paths between all pairs of vertices
void floydWarshall(int dist[MAX_NODES][MAX_NODES]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}
'''
This function impements the Floyd-Warshall algorithm to compute the shortest paths between all pairs of vertices. This is used later to determine the shortest additional edges required to transform a non-Eulerian graph into an Eulerian one.
