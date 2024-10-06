#include <stdio.h>
#include <stdlib.h>

// Arrays to store the knight's possible moves
int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

// Function to check if the move is valid
int isValidMove(int x, int y, int boardSizeX, int boardSizeY, int board[boardSizeX][boardSizeY]) {
    return (x >= 0 && x < boardSizeX && y >= 0 && y < boardSizeY && board[x][y] == -1);
}

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

int main() {
    int boardSizeX, boardSizeY;
    int startX, startY;

    // Input the board size
    printf("Input the board size (rows columns): ");
    scanf("%d %d", &boardSizeX, &boardSizeY);

    // Input the starting position of the knight
    printf("Input the starting position of the knight (row column): ");
    scanf("%d %d", &startX, &startY);

    // Dynamically allocate memory for the chessboard
    int board[boardSizeX][boardSizeY];
    int solution[boardSizeX * boardSizeY][2];  // To store the solution path

    // Initialize the chessboard with -1 (unvisited squares)
    for (int i = 0; i < boardSizeX; i++) {
        for (int j = 0; j < boardSizeY; j++) {
            board[i][j] = -1;
        }
    }

    // The knight starts at the given position
    board[startX][startY] = 0;
    solution[0][0] = startX;  // Store the starting x-coordinate
    solution[0][1] = startY;  // Store the starting y-coordinate

    // Try to solve the Knight's Tour from the starting position
    if (solveKnightTour(startX, startY, 1, boardSizeX, boardSizeY, board, solution)) {
        // Print the solution path
        for (int i = 0; i < boardSizeX * boardSizeY; i++) {
            printf("%d %d\n", solution[i][0], solution[i][1]);
        }
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
