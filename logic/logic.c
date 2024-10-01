#include "logic.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

void moveDown(Board *board) {
    rotateBoard(board);
    bool moved = false; 
    for (int i = 0; i < SIZE; i++) {
        moved |= slideArray(board->grid[i]);
    }
    rotateBoard(board);
    rotateBoard(board);
    rotateBoard(board);
    if (moved) {
        addRandom(board);
    }
    printBoard(board);
}

void moveLeft(Board *board) {
    bool moved = false;
    for (int i = 0; i < SIZE; i++) {
        moved |= slideArray(board->grid[i]);
    }
    if (moved) {
        addRandom(board);
    }
    printBoard(board);
}

void moveRight(Board *board) {
    invertBoard(board);
    bool moved = false;
    for (int i = 0; i < SIZE; i++) {
        moved |= slideArray(board->grid[i]);
    }
    invertBoard(board);
    if (moved) {
        addRandom(board);
    }
    printBoard(board);
}

void moveUp(Board *board) {
    invertBoard(board);
    rotateBoard(board);
    bool moved = false;
    for (int i = 0; i < SIZE; i++) {
        moved |= slideArray(board->grid[i]);
    }
    rotateBoard(board);
    if (moved) {
        addRandom(board);
    }
    printBoard(board);
}

int gameLoop(Board *board) {
    char input;

    while (true) {
        input = _getch();

        switch (input) {
            case 'w':
                moveUp(board);
                break;
            case 's':
                moveDown(board);
                break;
            case 'a':
                moveLeft(board);
                break;
            case 'd':
                moveRight(board);
                break;
            case 'q':
                exit(0);
                break;
            default:
                printf("Comando inválido!\n");
        }
        system("cls");
        printBoard(board);
    }
}
