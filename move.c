//
// Created by Tongxuan Wang on 2019-02-11.
//

#include "move.h"

#include <stdio.h>
#include "move.h"
#include "board.h"
#include "CursorTrakeWindow.h"

void logheader(FILE* fp, int nRows, int nCols) {
    fprintf(fp, "%c\n", 'X');
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            fprintf(fp, "%c", '*');
        }
        fprintf(fp, "%c", '\n');
    }
}

void logfile(FILE* fp, struct buildBoard_Structure* board, char piece, int colPos) {

    fprintf(fp, "               %c", '\n');
    fprintf(fp, "%c", '\n');

    for (int col = 0; col < board->numCols; ++col) {
        if (col == colPos) {
            fprintf(fp, "%c", piece);
        } else {
            fprintf(fp, "%c", ' ');
        }
    }

    fprintf(fp, "%c", '\n');

    for (int i = 0; i < board->numRows; ++i) {
        for (int j = 0; j < board->numCols; ++j) {
            fprintf(fp, "%c", board->board[i][j]);
        }
        fprintf(fp, "%c", '\n');
    }
}

Move getValidMove(struct buildBoard_Structure* board, GameWindow* gameboard, TurnType playerTurn, CursorTrackedWindow* win, FILE* fp) {
    Move move;

    while (true) {

        char input = wgetch(win->cursesWin);
        if (input == 'a' || input == 'j' || input == 'A' || input == 'J') {
            if (win->cursorCol > 0) {
                mvwaddch(win->cursesWin, 0, win->cursorCol, ' ');
                win->cursorCol -= 1;
                mvwaddch(win->cursesWin, 0, win->cursorCol, "XO"[playerTurn]);
                wmove(win->cursesWin, 0, win->cursorCol);
                wrefresh(win->cursesWin);

                logfile(fp, board, "XO"[playerTurn], win->cursorCol);
            } else if (win->cursorCol == 0) {
                mvwaddch(win->cursesWin, 0, win->cursorCol, ' ');
                win->cursorCol = board->numCols - 1;
                mvwaddch(win->cursesWin, 0, win->cursorCol, "XO"[playerTurn]);
                wmove(win->cursesWin, 0, board->numCols - 1);
                wrefresh(win->cursesWin);

                logfile(fp, board, "XO"[playerTurn], win->cursorCol);
            }
        } else if (input == 's' || input == 'k' || input == 'S' || input == 'K') {
            if (win->cursorCol < board->numCols - 1) {
                mvwaddch(win->cursesWin, 0, win->cursorCol, ' ');
                win->cursorCol += 1;
                mvwaddch(win->cursesWin, 0, win->cursorCol, "XO"[playerTurn]);
                wmove(win->cursesWin, 0, win->cursorCol);
                wrefresh(win->cursesWin);

                logfile(fp, board, "XO"[playerTurn], win->cursorCol);
            } else if (win->cursorCol == board->numCols - 1) {
                mvwaddch(win->cursesWin, 0, win->cursorCol, ' ');
                win->cursorCol = 0;
                mvwaddch(win->cursesWin, 0, win->cursorCol, "XO"[playerTurn]);
                wmove(win->cursesWin, 0, win->cursorCol);
                wrefresh(win->cursesWin);

                logfile(fp, board, "XO"[playerTurn], win->cursorCol);
            }

        } else if (input == ' ' || input == '\n') {

            for (int i = board->numRows - 1; i >= 0; i--) {
                if (board->board[i][win->cursorCol] == board->blankSpace) {
                    move.row = i;
                    move.col = win->cursorCol;
                    move.marker = "XO"[playerTurn];

                    if ('X' == move.marker) {
                        mvwaddch(win->cursesWin, 0, win->cursorCol, 'O');
                    } else {
                        mvwaddch(win->cursesWin, 0, win->cursorCol, 'X');
                    }
                    wrefresh(win->cursesWin);
                    return move;
                }
            }

            logfile(fp, board, "XO"[playerTurn], win->cursorCol);
        } else {
            logfile(fp, board, "XO"[playerTurn], win->cursorCol);
        }

    }
}

void updateboard(GBoard* board , GameWindow* gameboard, Move move, TurnType playerTurn, CursorTrackedWindow* win, FILE* fp){

    board->board[move.row][move.col] = move.marker;
    mvwaddch(gameboard->Win, move.row, move.col, playerTurn);
    wmove(win->cursesWin, 0, move.col);
    wrefresh(gameboard->Win);
    wrefresh(win->cursesWin);
}