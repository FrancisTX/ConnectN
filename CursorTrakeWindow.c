//
// Created by Tongxuan Wang on 2019-02-08.
//

#include "CursorTrakeWindow.h"

CursorTrackedWindow newCursorTrackedWindow(int numRows, int numCols, int rowStart, int colStart){
    CursorTrackedWindow window;
    window.cursesWin = newwin(numRows, numCols, rowStart, colStart);
    window.cursorCol = 0;
    return window;
}

GameWindow newGameBoard(int nRows, int nCols, int rowSta, int colSta){
    GameWindow gameWindow;
    gameWindow.Win = newwin(nRows, nCols, rowSta, colSta);
    gameWindow.Rowposition = rowSta;
    gameWindow.Colposition = 0;
    return gameWindow;
}

WinnerWindow getwinnnerwindow(int Rows, int Cols, int Row_start, int Col_start){
    WinnerWindow winnerwin;
    winnerwin.window = newwin(Rows, Cols, Row_start, Col_start);
    winnerwin.rowposition = Row_start;
    winnerwin.colposition = 0;
    return winnerwin;
}

void fillgameWindow(GameWindow* gameWindow , char fillChar){
//    int numberRow = gameWindow->Rowposition, numberCol = gameWindow->Colposition;

    for (int i = 0; i < getmaxy(gameWindow->Win); ++i) {
        for (int j = 0; j < getmaxx(gameWindow->Win); ++j) {
            mvwaddch(gameWindow->Win, i, j, fillChar);
        }
    }
//    wmove(gameWindow->Win, numberRow, numberCol);
}

void fillplayarea(CursorTrackedWindow* window, char fillChar){
    for (int i = 0; i < getmaxx(window->cursesWin); ++i) {
        mvwaddch(window->cursesWin, 0, i, fillChar);
    }
    wmove(window->cursesWin, 0, 0);
}

void fillwinnerwin(WinnerWindow* win, char fillchar){
    for (int i = 0; i < getmaxy(win->window); ++i){
        for (int j = 0; j < getmaxx(win->window); ++j) {
            mvwaddch(win->window, i, j, fillchar);
        }
    }
}


//int getNumRows(CursorTrackedWindow* gamewindow){
  //  return getmaxy(gamewindow->cursesWin);
//}
//int getNumCols(CursorTrackedWindow* gamewindow) {
//    return getmaxx(gamewindow->cursesWin);
//}



