//
// Created by Tongxuan Wang on 2019-02-11.
//

#ifndef NCURSESCONNECTN_MOVE_H
#define NCURSESCONNECTN_MOVE_H
#include <stdbool.h>
#include "CursorTrakeWindow.h"

typedef enum{Player1 = 0, Player2 = 1}TurnType;

typedef struct Move_Struct{
    int row, col;
    char marker;
}Move;

struct buildBoard_Structure;

void logheader(FILE* fp, int nRows, int nCols);
void logfile(FILE* fp, struct buildBoard_Structure* board, char piece, int colPos);
Move getValidMove(struct buildBoard_Structure* board, GameWindow* gameboard, TurnType playerTurn, CursorTrackedWindow* window, FILE* fp);
//bool isValidMove(Move move,  struct Board_Struct* board, int numArgsRead, int numArgsNeeded);
void updateboard(struct buildBoard_Structure* board , GameWindow* gameboard, Move move,  TurnType playerTurn, CursorTrackedWindow* win, FILE* fp);
const char* PlayerToString(TurnType player);

#endif //NCURSESCONNECTN_MOVE_H
