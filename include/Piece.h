#ifndef CHESS_ANDY_PIECE_H
#define CHESS_ANDY_PIECE_H

#include "Enums.h"

class Piece {
public:
    Piece(Color color, PieceType type);

    int getX();
    int getY();
    Color getColor();
    PieceType getPieceType();

protected:
    Color color;
    PieceType type;

private:
    int x;
    int y;
};

#endif //CHESS_ANDY_PIECE_H
