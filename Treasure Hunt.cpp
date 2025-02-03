#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_GUESSES 3

void initializeBoard(char board[ROWS][COLS], int* treasureRow, int* treasureCol) {
    // Initialize the board with '-'
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }

    // Place the treasure at a random location
    srand(time(NULL));
    *treasureRow = rand() % ROWS;
    *treasureCol = rand() % COLS;
}

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[ROWS][COLS];
    int treasureRow, treasureCol;
    int guessRow, guessCol;
    int guessesLeft = MAX_GUESSES;

    initializeBoard(board, &treasureRow, &treasureCol);

    printf("Welcome to the Treasure Hunt Game!\n");
    printf("You have %d guesses to find the hidden treasure.\n", MAX_GUESSES);

    while (guessesLeft > 0) {
        printf("\nCurrent board:\n");
        printBoard(board);

        printf("Enter your guess (row and column): ");
        scanf_s("%d %d", &guessRow, &guessCol);

        if (guessRow < 1 || guessRow > ROWS || guessCol < 0 || guessCol > COLS) {
            printf("Invalid guess. Please enter numbers between 1 and %d.\n", ROWS);
            continue;
        }

        guessRow--;
        guessCol--;

        if (guessRow == treasureRow && guessCol == treasureCol) {
            printf("Congratulations! You found the treasure!\n");
            board[guessRow][guessCol] = 'T';
            break;
        }
        else {
            printf("No treasure at (%d, %d). Try again!\n", guessRow + 1, guessCol + 1);
            board[guessRow][guessCol] = 'X';
            guessesLeft--;
        }
    }

    if (guessesLeft == 0) {
        printf("Game over! You've used all your guesses.\n");
        board[treasureRow][treasureCol] = 'T';
    }

    printf("\nFinal board:\n");
    printBoard(board);

    return 0;
}