#ifndef Game_H
#define Game_H
#include "Board.h"
#include "Snake.h"
#include "Stats.h"
#include "UserData.h"
#include "Food.h"
#include <stdbool.h>

typedef struct {
	Board board;
	Snake snake;
	Stats stats;
}Game;

bool init(Game* game);
int run(Game* game);
void reset(Game* game);
void handleSnakeDeath(Game* game);
#endif // !Game_H