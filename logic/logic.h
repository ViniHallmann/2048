#ifndef LOGIC_H
#define LOGIC_H

#include "board.h"

void moveUp(Board *board);
void moveDown(Board *board);
void moveLeft(Board *board);
void moveRight(Board *board);
int gameLoop(Board *board);

#endif
