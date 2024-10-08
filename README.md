# Graph Theory Week 7 Assignment

| Name  | NRP |
| ------------- | ------------- |
| Muh. Yusuf Haidar Khairullah  | 5111942000022  |
| Haidar Daffa Firzatullah  | 5025231071  |

## Traveling Salesman Problem
### Problem Description

The Travelling Salesman Problem (TSP) is a combinatorial optimization problem. Given a set of cities and the distances between each pair of cities, the task is to find the shortest possible tour that visits each city exactly once and returns to the starting city.

### Code Explanation

```
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
```
This function implements the core logic of the Traveling Salesman Problem using recursion and backtracking. It explores all possible paths from the current position (pos) and keeps track of the cost (cost) of visiting nodes

```
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
```
This function initiates the algorithm from a given start node by marking the start as visited and calling the recursive tsp function. After the recursion finishes, it prints the minimum cost and the best route found.



## Chinese Postman Problem
### Problem Description

The Chinese Postman Problem aims to find the shortest closed path or circuit that visits every edge of a graph at least once. This is particularly useful in logistics and postal routing scenarios.

### Code Explanation

```
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
```
This function initializes the graph by setting the diagonal to 0 (cost of self-loops) and all other edges to INF (no direct edges between nodes).

```
// Function to print the Eulerian circuit
void printCircuit(int start, int cost) {
    printf("Cost: %d\n", cost);
    printf("Route: ");
    
    // Here you can implement Hierholzer's algorithm to find the Eulerian Circuit
    // This is just a placeholder for the demonstration:
    printf("0, 1, 3, 2, 3\n");  // Replace this with your route calculation
}
```
Prints the Eulerian circuit and its total cost. The function currently contains a placeholder for the Eulerian circuit calculation (Hierholzer's algorithm can be used here).

```
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
```
Checks whether the graph is Eulerian by ensuring all vertices have even degrees. The function returns true if the graph is Eulerian and false otherwise.

```
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
```
This function impements the Floyd-Warshall algorithm to compute the shortest paths between all pairs of vertices. This is used later to determine the shortest additional edges required to transform a non-Eulerian graph into an Eulerian one.

## Knights Tour
### Problem Description
The program solves the Knight's Tour by attempting to move the knight to all possible valid squares on the board. If it reaches all squares, it prints the solution path. If no solution is found, the program backtracks and tries another sequence of moves.

### Code Explanation

```
// Function to check if the move is valid
int isValidMove(int x, int y, int boardSizeX, int boardSizeY, int board[boardSizeX][boardSizeY]) {
    return (x >= 0 && x < boardSizeX && y >= 0 && y < boardSizeY && board[x][y] == -1);
}
```
This function checks whether a move is valid. A move is considered valid if:
- The new position (x, y) lies within the boundaries of the board.
- The new position has not been visited yet.

```
// Function to solve the Knight's Tour using backtracking and print the coordinates
int solveKnightTour(int x, int y, int moveCount, int boardSizeX, int boardSizeY, int board[boardSizeX][boardSizeY], int solution[boardSizeX * boardSizeY][2]) {
    // Base case: If all squares are visited
    if (moveCount == boardSizeX * boardSizeY) {
        return 1;
    }

    // Try all 8 possible moves for the knight
    for (int i = 0; i < 8; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        // Check if the move is valid
        if (isValidMove(nextX, nextY, boardSizeX, boardSizeY, board)) {
            board[nextX][nextY] = moveCount;  // Make the move
            solution[moveCount][0] = nextX;   // Store the x-coordinate in solution
            solution[moveCount][1] = nextY;   // Store the y-coordinate in solution

            // Recursively attempt to solve the next move
            if (solveKnightTour(nextX, nextY, moveCount + 1, boardSizeX, boardSizeY, board, solution)) {
                return 1;  // Solution found
            }

            // Backtrack: Undo the move
            board[nextX][nextY] = -1;
        }
    }

    return 0;  // No solution found
}
```
This function implements the core backtracking algorithm:

- Base Case: If moveCount equals the total number of squares on the board, the tour is complete, and the function returns 1.
- Recursive Case: The knight attempts all eight possible moves. If a move is valid, it updates the board, stores the move in solution, and recursively calls the function to attempt the next move. If a solution is found, the function returns 1. If not, it backtracks by resetting the current square to -1 and tries another move.
