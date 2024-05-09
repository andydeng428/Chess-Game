#include "Pawn.h"

Pawn::Pawn(Color color) : Piece(color, PieceType::PAWN) {
    canDoubleMove = true;
}

void Pawn::promote(PieceType type) {
    this->type = type;
}

void Pawn::performedDoubleMove() {
    canDoubleMove = false;
}
