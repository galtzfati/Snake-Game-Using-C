#ifndef Board_C
#define Board_C
#include "Board.h"

Board createBoard(int height, int width) {
    Board board;
    board.height = height;
    board.width = width;
    buildBoard(&board);
    fillBoard(&board);
    return board;
}
void buildBoard(Board* board)
{
    board->board = (char**)malloc(sizeof(char*) * board->height);
    if (board->board == NULL) {
        system("cls");
        printf("Memory allocation error. Exiting...");
        exit(1);
    }
    for (int i = 0; i < board->height; i++) {
        board->board[i] = (char*)malloc(sizeof(char) * board->width);
        if (board->board[i] == NULL) {
            system("cls");
            printf("Memory allocation error. Exiting...");
            exit(1);
        }
    }
}
void fillBoard(Board* board) {
    for (int i = 0; i < board->height; i++) {
        for (int j = 0; j < board->width; j++) {
            // Setting borders
            if (i == 0 || i == board->height - 1 || j == 0 || j == board->width - 1) {
                board->board[i][j] = BORDER;
            }
            // Setting movement area
            else {
                board->board[i][j] = BLANK;
            }
        }
    }
    // Setting tunnels
    board->board[board->height / 2][0] = TUNNEL;
    board->board[board->height / 2][board->width - 1] = TUNNEL;
    board->board[0][board->width / 2] = TUNNEL;
    board->board[board->height - 1][board->width / 2] = TUNNEL;
}
void printBoard(Board* board, Position snakeHead) {
    gotoxy(0, 0);
    for (int i = 0; i < board->height; i++) {
        for (int j = 0; j < board->width; j++) {
            if (board->board[i][j] == BORDER) {
                PRINT_BORDER();
            }
            else if (board->board[i][j] == FOOD) {
                PRINT_FOOD();
            }
            else if (board->board[i][j] == TUNNEL) {
                PRINT_TUNNEL();
            }
            else if (board->board[i][j] == SNAKE) {
                PRINT_SNAKE_BODY();
            }
            else {
                PRINT_BLANK();
            }
        }
        printf("\n");
    }
    gotoxy(snakeHead.column, snakeHead.row);
    PRINT_SNAKE_HEAD();
}
void freeBoard(Board* board) {
    for (int i = 0; i < board->height; i++) {
        free(board->board[i]);
    }
    free(board->board);
}
#endif // !Board_C