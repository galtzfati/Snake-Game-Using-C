#define _CRT_SECURE_NO_WARNINGS
#ifndef Stats_H
#define Stats_H
#include "Board.h"
#include "Utils.h"
#include "UserData.h"
#define LIVES 3

typedef struct {
	int score;
	int lives;
	int speed;
	char level[10];
}Stats;

void printStats(Board* board, Stats* stats);
Stats getStats(UserData* userData);
void updateScore(int* score);
void updateLives(int* lives);
#endif // !Stats_H