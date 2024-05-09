#ifndef CHESS_ANDY_PAWN_H
#define CHESS_ANDY_PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(Color color);

    void promote(PieceType type);
    void performedDoubleMove();

protected:
    bool canDoubleMove;
};

#endif //CHESS_ANDY_PAWN_H
