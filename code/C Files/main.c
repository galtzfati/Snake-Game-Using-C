#ifndef Main_C
#define Main_C
#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"

int main() {
	
	Game game;
	bool ready;
	int score;
	do {
		ready = init(&game);
		if (ready) {
			score = run(&game);

			reset(&game);

			system("cls");
			printf("Game Over.\nYour Score: %d.\n", score);
		}
	} while (ready);
	goodbye();
	return 0;
}

#endif // !Main_C