#ifndef Constants_H
#define Constants_H
#include <stdio.h>

// Special Keys
#define UP		72  // Up Arrow 
#define DOWN	80 // Down Arrow 
#define LEFT	75  // Left Arrow 
#define RIGHT	77  // Right Arrow 
#define ESC		27  // Escape Key
// Sizes
#define SNAKE_INITIAL_SIZE	5
// Symbols
#define SNAKE		2	// Smiley
#define FOOD		3	// Heart
#define BORDER		'#'
#define BLANK		' '
#define TUNNEL		'O'
// Levels
#define EASY 1
#define MEDIUM 2
#define HARD 3
#define ULTRA 4
#define EXIT 0
// Colors
#define ANSI_COLOR_RED "\033[0;31m"
#define ANSI_COLOR_GREEN "\033[0;32m"
#define ANSI_COLOR_YELLOW "\033[1;33m"
#define ANSI_COLOR_BLUE "\033[0;34m"
#define ANSI_COLOR_MAGENTA "\033[0;35m"
#define ANSI_COLOR_CYAN "\033[0;36m"
#define ANSI_COLOR_RESET "\033[0m"

#define PRINT_FOOD() printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET, FOOD)
#define PRINT_SNAKE_BODY() printf(ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET, SNAKE)
#define PRINT_SNAKE_HEAD() printf(ANSI_COLOR_CYAN "%c" ANSI_COLOR_RESET, SNAKE)
#define PRINT_STATS(level, lives, score) printf(ANSI_COLOR_MAGENTA "Level: %s | Lives: %d | Score: %d" ANSI_COLOR_RESET, level, lives, score)
#define PRINT_BORDER() printf(ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET, BORDER)
#define PRINT_TUNNEL() printf(ANSI_COLOR_YELLOW "%c" ANSI_COLOR_RESET, TUNNEL)
#define PRINT_BLANK() printf("%c", BLANK)

#endif // !Constants_H