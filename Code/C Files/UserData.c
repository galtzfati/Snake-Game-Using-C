#ifndef UserData_C
#define UserData_C
#include "UserData.h"

UserData getDataFromUser() {
	UserData userData = {0, 0, 0, 0};
	greetUser();
	
	int level;
	char c;
	bool error = false;
	do {
		if (error) {
			system("cls");
			printf("Invalid input.\n");
			while ((c = getchar()) != '\n' && c != EOF) {
				// discard characters from stdin
			}
		}
		printf("Choose game level:\n");
		printf("1. Easy\n");
		printf("2. Medium\n");
		printf("3. Hard\n");
		printf("4. Ultra\n");
		printf("0. Exit\n");
		printf("Level: ");
	} while (error = scanf("%d", &level) != 1 || level < EXIT || level > ULTRA);

	switch (level) {
	case EASY:
		strcpy(userData.level, "Easy\0");
		userData.height = 20;
		userData.width = 40;
		userData.speed = 150;
	case MEDIUM:
		strcpy(userData.level, "Medium\0");
		userData.height = 20;
		userData.width = 40;
		userData.speed = 100;
		break;
	case HARD:
		strcpy(userData.level, "Hard\0");
		userData.height = 15;
		userData.width = 30;
		userData.speed = 100;
		break;
	case ULTRA:
		strcpy(userData.level, "Ultra\0");
		userData.height = 15;
		userData.width = 30;
		userData.speed = 50;
		break;
	case EXIT:
		strcpy(userData.level, "Exit\0");
		userData.height = 0;
		userData.width = 0;
		userData.speed = 0;
		break;
	}
	system("cls");
	
	return userData;
}
void greetUser() {
	printf("Hello! Welcome to the Snake game!\n");
}
#endif // !UserData_C