#include "Piece.h"

Piece::Piece(Color color, PieceType type) : color(color), type(type){}

int Piece::getX() {
    return x;
}

int Piece::getY() {
    return y;
}

Color Piece::getColor() {
    return color;
}

PieceType Piece::getPieceType() {
    return type;
}
