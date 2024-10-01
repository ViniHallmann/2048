#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void addRandom(Board *board) {
    static bool initialized = false;

    if (!initialized) {
        srand(time(NULL));
        initialized = true;
    }

    int row = rand() % SIZE;
    int col = rand() % SIZE;

    while (board->grid[row][col] != 0) {
        row = rand() % SIZE;
        col = rand() % SIZE;
    }

    board->grid[row][col] = 2;
}

void initBoard(Board **board) {
    *board = (Board *)malloc(sizeof(Board));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            (*board)->grid[i][j] = 0;
        }
    }
    addRandom(*board);
    addRandom(*board);
}

void printBoard(Board *board) {
    printf("\n===========2048==========\n");

    for (int i = 0; i < SIZE; i++) {
        printf("| ");
        for (int j = 0; j < SIZE; j++) {
            if (board->grid[i][j] == 0) {
                printf("0   | ");
            }
            else {
                printf("%-4d| ", board->grid[i][j]);
            }
        }
        printf("\n");
        printf("------------------------\n");
    }

    //printf("\nPREV -> P\nRESTART -> R\nEXIT -> U\n");
    printf("ENTER YOUR CHOICE -> W,S,A,D\n");
}

void transposeBoard(Board *board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            int temp = board->grid[i][j];
            board->grid[i][j] = board->grid[j][i];
            board->grid[j][i] = temp;
        }
    }
}

void invertBoard(Board *board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            int temp = board->grid[i][j];
            board->grid[i][j] = board->grid[i][SIZE - j - 1];
            board->grid[i][SIZE - j - 1] = temp;
        }
    }
}

void rotateBoard(Board *board) {
    transposeBoard(board);
    invertBoard(board);
}
