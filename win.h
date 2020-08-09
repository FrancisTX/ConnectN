//
// Created by Tongxuan Wang on 2019-02-08.
//

#ifndef NCURSESCONNECTN_WIN_H
#define NCURSESCONNECTN_WIN_H

#include <stdio.h>
#include "board.h"
#include "move.h"


bool endGame(GBoard board, int numToWin);
bool win(GBoard board, int numToWin);
bool horzWin(GBoard board, int numToWin);
bool vertWin(GBoard board, int numToWin);
bool diagWin(GBoard board, int numToWin);
bool rightDiagWin(GBoard board, int numToWin);
bool leftDiagWin(GBoard board, int numToWin);
bool tie(GBoard board, int numToWin);

int declareWinner(GBoard board, TurnType playerTurn, int numToWin);

#endif //NCURSESCONNECTN_WIN_H
