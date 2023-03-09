#ifndef Snake_C
#define Snake_C
#include "Snake.h"

Snake createSnake(Board* board) {
	Snake snake;
	resetSnake(board, &snake);
	return snake;
}
Position getSnakeNextMove(Board* board, Snake* snake) {
	if (_kbhit()) // if any key was hit
		snake->currentMove = getKey(); // change direction
	if (snake->currentMove == RIGHT || snake->currentMove == LEFT 
		|| snake->currentMove == UP || snake->currentMove == DOWN 
		|| snake->currentMove == ESC) {
		snake->lastMove = snake->currentMove;
	}
	else
		snake->currentMove = snake->lastMove;
	
	Position newHead = snake->body.head->position;

	switch (snake->currentMove) {
		case RIGHT:
			newHead.column++;
			break;
		case DOWN:
			newHead.row++;
			break;
		case LEFT:
			newHead.column--;
			break;
		case UP:
			newHead.row--;
			break;
	}

	return newHead;
}
bool isMoveValid(Board* board, Snake* snake, Position newPosition) {
	// Returns true if the next position of the snake is not on the border of the board,
	// or if it is on the snake's body (excluding the head).
	// If the next position is the head, it means the user has pressed the "ESC" key,
	// indicating that the snake should not move at all.
	// This is a legitimate option in this implementation.
	return !(
				board->board[newPosition.row][newPosition.column] == BORDER
			|| 
				(board->board[newPosition.row][newPosition.column] == SNAKE
					&& !areSamePositions(snake->body.head->position, newPosition)
				)
		);
}
void moveSnake(Board* board, Snake* snake, Position newPosition) {
	if (areSamePositions(snake->body.head->position, newPosition)) {
		return;
	}
	else if (board->board[newPosition.row][newPosition.column] == TUNNEL) {
		if (newPosition.row == 0) {
			newPosition.row = board->height - 2;
		}
		else if (newPosition.row == board->height - 1) {
			newPosition.row = 1;
		}
		if (newPosition.column == 0) {
			newPosition.column = board->width - 2;
		}
		else if (newPosition.column == board->width - 1) {
			newPosition.column = 1;
		}
	}

	gotoxy(snake->body.tail->position.column, snake->body.tail->position.row);
	PRINT_BLANK();
	gotoxy(snake->body.head->position.column, snake->body.head->position.row);
	PRINT_SNAKE_BODY();
	gotoxy(newPosition.column, newPosition.row);
	PRINT_SNAKE_HEAD();

	board->board[snake->body.tail->position.row][snake->body.tail->position.column] = BLANK;
	board->board[newPosition.row][newPosition.column] = SNAKE;
	deleteFromTail(&snake->body);
	insertToHead(&snake->body, newPosition);
	gotoxy(0, 0);
}
void extendSnakeBody(Board* board, Snake* snake, Position newHead) {
	gotoxy(snake->body.head->position.column, snake->body.head->position.row);
	PRINT_SNAKE_BODY();
	gotoxy(newHead.column, newHead.row);
	PRINT_SNAKE_HEAD();
	board->board[newHead.row][newHead.column] = SNAKE;
	insertToHead(&snake->body, newHead);
	gotoxy(0, 0);
}
void resetSnake(Board* board, Snake* snake) {
	snake->size = SNAKE_INITIAL_SIZE;
	snake->currentMove = ESC;
	snake->lastMove = ESC;
	makeEmptyList(&snake->body);

	Position snakeBody;
	snakeBody.row = board->height / 2;
	snakeBody.column = board->width / 2;

	for (int i = 0; i < snake->size; i++) {
		board->board[snakeBody.row][snakeBody.column] = SNAKE;
		insertToTail(&snake->body, snakeBody);
		snakeBody.column--;
	}
}
void freeSnake(Snake* snake) {
	freeList(&snake->body);
}
int getKey()
{
	char KeyStroke = _getch();
	if (KeyStroke == 0 || KeyStroke == -32)
		KeyStroke = _getch();
	return (KeyStroke);
}
#endif // !Snake_C