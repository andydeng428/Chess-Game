#ifndef CHESS_ANDY_BOARD_H
#define CHESS_ANDY_BOARD_H

#include "Piece.h"

class Board {
public:
    Board();
    ~Board();

    bool isOccupied(int x, int y);
    Piece* getPiece(int x, int y);
    void movePiece(Board& board, int endX, int endY, int startX, int startY);
    void setPiece(int x, int y, Piece* piece);

private:
    Piece* board[8][8];
};

#endif //CHESS_ANDY_BOARD_H
