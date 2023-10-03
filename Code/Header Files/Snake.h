#ifndef Snake_H
#define Snake_H
#include <stdbool.h>
#include "Position.h"
#include "Constants.h"
#include "Board.h"
#include "List.h"
#include "Utils.h"

typedef struct {
	List body;
	int size;
	char currentMove;
	char lastMove;
}Snake;

Snake createSnake(Board* board);
Position getSnakeNextMove(Board* board, Snake* snake);
bool isMoveValid(Board* board, Snake* snake, Position newPosition);
void moveSnake(Board* board, Snake* snake, Position newPosition);
void extendSnakeBody(Board* board, Snake* snake, Position newHead);
void resetSnake(Board* board, Snake* snake);
void freeSnake(Snake* snake);
int getKey();
#endif // !Snake_H