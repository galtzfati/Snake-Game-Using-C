#ifndef Food_C
#define Food_C
#include "Food.h"

void randomFood(Board* board) {
	Position foodPosition;
	do {
		foodPosition.row = 1 + rand() % (board->height - 2);
		foodPosition.column = 1 + rand() % (board->width - 2);
	} while (board->board[foodPosition.row][foodPosition.column] == SNAKE);

	board->board[foodPosition.row][foodPosition.column] = FOOD;
	gotoxy(foodPosition.column, foodPosition.row);
	PRINT_FOOD();
	gotoxy(0, 0);
}
bool isFoodEaten(Board* board, Position newPosition) {
	return board->board[newPosition.row][newPosition.column] == FOOD;
}
#endif // !Food_C