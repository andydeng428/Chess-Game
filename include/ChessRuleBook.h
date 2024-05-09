#ifndef CHESS_ANDY_CHESSRULEBOOK_H
#define CHESS_ANDY_CHESSRULEBOOK_H

#include "Board.h"

class ChessRuleBook {
public:
    static bool isMoveLegal(Piece* piece, const Board& board, int startX, int startY, int endX, int endY);

private:
    bool isMoveLegalForPawn(const Board& board, Color color, int startX, int startY, int endX, int endY);
    bool isMoveLegalForKnight(const Board& board, Color color, int startX, int startY, int endX, int endY);
    bool isMoveLegalForBishop(const Board& board, Color color, int startX, int startY, int endX, int endY);
    bool isMoveLegalForRook(const Board& board, Color color, int startX, int startY, int endX, int endY);
    bool isMoveLegalForQueen(const Board& board, Color color, int startX, int startY, int endX, int endY);
    bool isMoveLegalForKing(const Board& board, Color color, int startX, int startY, int endX, int endY);
};
#endif //CHESS_ANDY_CHESSRULEBOOK_H
