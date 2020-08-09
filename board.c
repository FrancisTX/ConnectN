//
// Created by Tongxuan Wang on 2019-02-06.
//

#include "board.h"

#include <stdio.h>
#include <stdlib.h>

GBoard buildBoard(int numRows, int numCols, char blankSpace){
    GBoard board;

    board.board = (char**)malloc(numRows * sizeof(char*));
    for (int i = 0; i < numRows; ++i){
        board.board[i] = (char*)malloc(numCols * sizeof(char));
        for (int j = 0; j < numCols; ++j){
            board.board[i][j] = blankSpace;
        }
    }

    board.numRows = numRows;
    board.numCols = numCols;
    board.blankSpace = blankSpace;
    return board;
}

void cleanUpBoard(GBoard* board) {

    for (int row = 0; row < board->numRows; ++row) {
        free(board->board[row]);
    }
    free(board->board);
    board->board = NULL;
    board->numRows = 0;
    board->numCols = 0;
}

