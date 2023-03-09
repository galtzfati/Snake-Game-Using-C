#ifndef Position_C
#define Position_C
#include "Position.h"

bool areSamePositions(Position a, Position b) {
	return a.column == b.column && a.row == b.row;
}

#endif // !Position_C