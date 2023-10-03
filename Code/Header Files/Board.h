#ifndef Board_H
#define Board_H
#include <stdlib.h>
#include "Constants.h"
#include "Position.h"
#include "Utils.h"

typedef struct {
	int height;
	int width;
	char** board;
}Board;

Board createBoard(int height, int width);
void buildBoard(Board* board);
void fillBoard(Board* board);
void printBoard(Board* board, Position snakeHead);
void freeBoard(Board* board);

#endif // !Board_H