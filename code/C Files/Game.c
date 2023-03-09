#ifndef Game_C
#define Game_C
#include "Game.h"

bool init(Game* game) {
	srand(time(NULL));
	UserData userData = getDataFromUser();
	if (strcmp(userData.level, "Exit") == 0) {
		return false;
	}
	game->board = createBoard(userData.height, userData.width);
	game->snake = createSnake(&game->board);
	game->stats = getStats(&userData);
	randomFood(&game->board);
	printBoard(&game->board, game->snake.body.head->position);
	printStats(&game->board, &game->stats);
	return true;
}
int run(Game* game) {
	Position nextPosition;
	bool valid;

	do {
		nextPosition = getSnakeNextMove(&game->board, &game->snake);
		if (valid = isMoveValid(&game->board, &game->snake, nextPosition)) {
			if (isFoodEaten(&game->board, nextPosition)) {
				extendSnakeBody(&game->board, &game->snake, nextPosition);
				randomFood(&game->board);
				updateScore(&game->stats.score);
				printStats(&game->board, &game->stats);
			}
			else {
				moveSnake(&game->board, &game->snake, nextPosition);
			}
		}
		else {
			handleSnakeDeath(game);
		}
		Sleep(game->stats.speed);
	} while (game->stats.lives > 0);
	Sleep(450);
	
	return game->stats.score;
}
void reset(Game* game) {
	freeBoard(&game->board);
	freeSnake(&game->snake);
}
void handleSnakeDeath(Game* game) {
	fillBoard(&game->board);
	resetSnake(&game->board, &game->snake);
	updateLives(&game->stats.lives);
	printBoard(&game->board, game->snake.body.head->position);
	randomFood(&game->board);
	printStats(&game->board, &game->stats);
}
#endif // !Game_C