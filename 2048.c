#include "board/board.h"
#include "logic/logic.h"
#include <stdlib.h>

int main() {
    Board *board;

    initBoard(&board);
    printBoard(board);
    gameLoop(board);
    free(board);
}
