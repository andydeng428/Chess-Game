#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Piece.h"
#include "Color.h"

class ChessGame {
public:
    ChessGame();
    void startGame();
    void drawBoard(sf::RenderWindow &window);
    void handleClick(int x, int y);

private:
    void initializeBoard();
    bool performMove(int startX, int startY, int endX, int endY);
    bool isCheckmate(Color playerColor);
    bool isStalemate(Color currentPlayer, const Board& board);
    bool isGameEnded(Color currentPlayer, const Board& board);
    bool isKingInCheck(Color playerColor, int kingX, int kingY);

    Board board;
    Color currentPlayer;
    bool selected;
    int selectedX, selectedY;
};

#endif // CHESSGAME_H
