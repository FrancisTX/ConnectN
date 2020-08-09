//
// Created by Tongxuan Wang on 2019-02-08.
//

#ifndef NCURSESCONNECTN_CURSORTRAKEWINDOW_H
#define NCURSESCONNECTN_CURSORTRAKEWINDOW_H

#include <ncurses.h>

typedef struct CursorTrackedWindow_Struct{
    WINDOW* cursesWin;
    int cursorCol;
}CursorTrackedWindow;

typedef struct GameWindow_Struct{
    WINDOW* Win;
    int Rowposition, Colposition;
}GameWindow;

typedef struct Winnerwin_Struct{
   WINDOW* window;
    int rowposition, colposition;
}WinnerWindow;

CursorTrackedWindow newCursorTrackedWindow(int numRows, int numCols, int rowStart, int colStart);
GameWindow newGameBoard(int nRows, int nCols, int rowSta, int colSta);
WinnerWindow getwinnnerwindow(int Rows, int Cols, int Row_start, int Col_start);

//int getNumRows(CursorTrackedWindow* win);
//int getNumCols(CursorTrackedWindow* win);

void fillgameWindow(GameWindow* gameWindow , char fillChar);
void fillplayarea(CursorTrackedWindow* window, char fillChar);
void fillwinnerwin(WinnerWindow* win, char fillchar);

#endif //NCURSESCONNECTN_CURSORTRAKEWINDOW_H
