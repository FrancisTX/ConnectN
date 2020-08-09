#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "board.h"
#include "move.h"
#include "win.h"
#include "CursorTrakeWindow.h"


int main(int argc, char* argv[]) {


    initscr();
    noecho();
    cbreak();

    int numRows = atoi(argv[1]);
    int numCols = atoi(argv[2]);
    int numtowin = atoi(argv[3]);
    FILE *fp = fopen(argv[4], "w");

    CursorTrackedWindow playarea = newCursorTrackedWindow(1, numCols, 0, 0);
    fillplayarea(&playarea, ' ');
    wrefresh(playarea.cursesWin);

    GameWindow gameboard = newGameBoard(numRows, numCols, 1, 0);
    fillgameWindow(&gameboard, '*');
    wrefresh(gameboard.Win);

    GBoard board = buildBoard(numRows, numCols, '*');

    TurnType playerTurn = Player1;

    mvwaddch(playarea.cursesWin, 0, 0, "XO"[playerTurn]);
    wmove(playarea.cursesWin, 0, 0);

    WinnerWindow winnerarea = getwinnnerwindow(2, 15, numRows + 1, 0);
    fillwinnerwin(&winnerarea, ' ');

    wrefresh(winnerarea.window);
    wrefresh(gameboard.Win);
    wrefresh(playarea.cursesWin);

    logheader(fp, numRows, numCols);

    if (numtowin == 1) {

        while (1) {
            char input = wgetch(playarea.cursesWin);

            if (input == ' ' || input == '\n') {
                Move move;
                move.marker = 'X';
                move.row = 0;
                move.col = 0;
                updateboard(&board, &gameboard, move, 'X', &playarea, fp);
                wmove(winnerarea.window, 0, 0);
                waddstr(winnerarea.window, "Player 1 win!");
                wrefresh(winnerarea.window);
                logfile(fp, &board, 'X', 0);
                fprintf(fp, "%s", "Player 1 won!  ");
                break;
            } else {
                logfile(fp, &board, 'X', 0);
            }
        }
    } else {
        while (!endGame(board, numtowin)) {
            Move move = getValidMove(&board, &gameboard, playerTurn, &playarea, fp);
            updateboard(&board, &gameboard, move, "XO"[playerTurn], &playarea, fp);
            if (!endGame(board, numtowin)) {
                if ('X' == move.marker) {
                    logfile(fp, &board, 'O', move.col);
                } else {
                    logfile(fp, &board, 'X', move.col);
                }
            } else {
                logfile(fp, &board, move.marker, move.col);
            }
            playerTurn = playerTurn == Player1 ? Player2 : Player1;
        }

        wmove(winnerarea.window, 0, 0);

        if (declareWinner(board, playerTurn, numtowin) == 1) {
            waddstr(winnerarea.window, "Player 1 win!");
            fprintf(fp, "%s", "Player 1 won!  ");
        } else if (declareWinner(board, playerTurn, numtowin) == 2) {
            waddstr(winnerarea.window, "Player 2 win!");
            fprintf(fp, "%s", "Player 2 won!  ");
        } else {
            waddstr(winnerarea.window, "Tie!");
            fprintf(fp, "%s", "Tie Game       ");
        }
        wmove(winnerarea.window, 0, 0);
        wrefresh(winnerarea.window);
    }

    fclose(fp);

    getchar();
    endwin();
    cleanUpBoard(&board);

    return 0;
}
