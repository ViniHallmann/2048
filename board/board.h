#ifndef BOARD_H
#define BOARD_H

#define SIZE 4

typedef struct {
    int grid[SIZE][SIZE];
} Board;

void initBoard     ( Board **board );
void printBoard     ( Board *board );
void addRandom      ( Board *board );
void transposeBoard ( Board *board );
void invertBoard    ( Board *board );
void rotateBoard    ( Board *board );

#endif
