//
// Created by Tongxuan Wang on 2019-02-08.
//

#include "win.h"
#include <stdio.h>

bool endGame(GBoard board, int numToWin){
    return win(board, numToWin) || tie(board, numToWin);
}

bool win(GBoard board, int numToWin){
    return horzWin(board, numToWin) || vertWin(board, numToWin) || diagWin(board, numToWin);
}

bool horzWin(GBoard board, int numToWin){
    int numInRow;

    for (int row = 0; row < board.numRows; ++row){
        for (int col = 0; col < board.numCols; ++col) {
            if (board.board[row][col] != '*') {
                numInRow = 1;
                for (int i = 1; col + i < board.numCols; ++i){
                    if (board.board[row][col + i] == board.board[row][col]) {
                        numInRow += 1;
                        if (numInRow == numToWin) {
                            return true;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return false;
}

bool vertWin(GBoard board, int numToWin) {
    int numInvert;
    for (int row = 0; row < board.numRows; ++row) {
        for (int col = 0; col < board.numCols; ++col) {
            if (board.board[row][col] != '*') {
                numInvert = 1;
                for (int i = 1; row + i < board.numRows; ++i){
                    if (board.board[row + i][col] == board.board[row][col]) {
                        numInvert += 1;
                        if (numInvert == numToWin) {
                            return true;
                        }
                    } else {
                            break;
                    }
                }
            }
        }
    }
    return false;
}

bool diagWin(GBoard board, int numToWin){
    return leftDiagWin(board, numToWin) || rightDiagWin(board, numToWin);
}

bool rightDiagWin(GBoard board, int numToWin){
    int numInDiag;
    for (int row = 0; row < board.numRows; ++row) {
        for (int col = 0; col < board.numCols; ++col) {
            if (board.board[row][col] != '*') {
                numInDiag = 1;
                for (int i = 1; (row + i < board.numRows) && (col + i < board.numCols); ++i){
                    if (board.board[row + i][col + i] == board.board[row][col]){
                        numInDiag += 1;
                        if (numInDiag == numToWin) {
                            return true;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return false;
}

bool leftDiagWin(GBoard board, int numToWin){
    int numInDiag;
    for (int row = 0; row < board.numRows; ++row) {
        for (int col = 0; col < board.numCols; ++col) {
            if (board.board[row][col] != '*') {
                numInDiag = 1;
                for (int i = 1; (row + i < board.numRows) && (col - i >= 0); ++i){
                    if (board.board[row + i][col - i] == board.board[row][col]){
                        numInDiag += 1;
                        if (numInDiag == numToWin){
                            return true;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return false;
}

bool tie(GBoard board, int numToWin){
    if (win(board, numToWin)){
        return false;
    }
    for (int row = 0; row < board.numRows; ++row) {
        for (int col = 0; col < board.numCols; ++col) {
            if(board.board[row][col] == '*'){
                return false;
            }
        }
    }
    return true;
}

int declareWinner(GBoard board, TurnType playerTurn, int numToWin){
    int winner;
    if (win(board, numToWin)) {
        //if someone one it would actually be the loser's turn
        //so account for this here
        winner = playerTurn == Player1 ? Player2 : Player1;
        winner++;
    } else {
        winner = 3;
    }
    return winner;
}












