#ifndef Utils_C
#define Utils_C
#include "Utils.h"

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void goodbye() {
	printf("BBBBB   Y   Y   EEEEE\n");
	printf("B    B   Y Y    E    \n");
	printf("BBBBB     Y     EEEEE \n");
	printf("B    B    Y     E    \n");
	printf("BBBBB     Y     EEEEE\n");
}
#endif // !Utils_C
