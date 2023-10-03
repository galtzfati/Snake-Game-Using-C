#ifndef Food_H
#define Food_H
#include <stdlib.h>
#include <time.h>
#include "Position.h"
#include "Board.h"
#include "Utils.h"
#include <stdbool.h>

void randomFood(Board* board);
bool isFoodEaten(Board* board, Position newPosition);

#endif // !Food_H