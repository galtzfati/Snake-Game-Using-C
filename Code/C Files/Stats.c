#ifndef Stats_C
#define Stats_C
#include "Stats.h"

void printStats(Board* board, Stats* stats) {
	gotoxy(0, board->height);
	PRINT_STATS(stats->level, stats->lives, stats->score);
}
Stats getStats(UserData* userData) {
	Stats stats;
	strcpy(stats.level, userData->level);
	stats.speed = userData->speed;
	stats.lives = LIVES;
	stats.score = 0;
	return stats;
}
void updateScore(int* score) {
	(*score)++;
}
void updateLives(int* lives) {
	(*lives)--;
}
#endif // !Stats_C