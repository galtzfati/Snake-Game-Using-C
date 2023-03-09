#ifndef Position_H
#define Position_H
#include <stdbool.h>

typedef struct {
	int row;
	int column;
}Position;

bool areSamePositions(Position a, Position b);

#endif // !Position_H