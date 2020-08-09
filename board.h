//
// Created by Tongxuan Wang on 2019-02-06.
//

#ifndef NCURSESCONNECTN_BOARD_H
#define NCURSESCONNECTN_BOARD_H


typedef struct buildBoard_Structure{
    char** board;
    int numRows, numCols;
    char blankSpace;
}GBoard;

GBoard buildBoard(int numRows, int numCols, char blankSpace);
void cleanUpBoard(GBoard* board);
#endif //NCURSESCONNECTN_BOARD_H
