#define _CRT_SECURE_NO_WARNINGS
#ifndef UserData_H
#define UserData_H
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include "Constants.h"

typedef struct {
	int height;
	int width;
	int speed;
	char level[10];
}UserData;

UserData getDataFromUser();
void greetUser();
#endif // !UserData_H