#ifndef CHESS_ANDY_CHESSGAME_H
#define CHESS_ANDY_CHESSGAME_H

#include "Board.h"
#include "ChessRuleBook.h"

class ChessGame {
public:
    ChessGame();
    void startGame();

private:
    Color currentPlayer;
    Board board;
    ChessRuleBook ruleBook;

    void initializeBoard();
    bool performMove(int startX, int startY, int endX, int endY);
    bool isCheckmate(Color playerColor);
    bool isStalemate(Color currentPlayer, const Board& board);
    bool isGameEnded();
    void displayWinner();
};

#endif //CHESS_ANDY_CHESSGAME_H
