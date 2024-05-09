#include "Board.h"

Board::Board() {
    for (int i = 0; i < 8; i++) {
        for (int k = 0; k < 8; k++) {
            board[i][k] = nullptr;
        }
    }
}

Board::~Board() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] != nullptr) {
                delete board[i][j];
                board[i][j] = nullptr;
            }
        }
    }
}

bool Board::isOccupied(int x, int y) {
    return board[x][y] != nullptr;
}

Piece* Board::getPiece(int x, int y) {
    return board[x][y];
}

void setPiece(int x, int y, Piece* piece) {
    // Add bounds checking or other logic here
    board[x][y] = piece;
}

void Board::movePiece(Board& board, int endX, int endY, int startX, int startY) {
    // check if start location has piece
    if (!isOccupied(startX, startY)){
        return;
    }
    //get pointer to piece
    Piece* piece = board.getPiece(x, y);
    if (!ChessRuleBook::isMoveLegal(board, piece, startX, startY, endX, endY)){ //failsafe
        return;
    }
    //remove object
    if (isOccupied(endX, endY)){
        delete board[endX][endY];
        board[endx][endY] = nullptr;
    }
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = nullptr;

    //condition for pawn: check if move was double move and mark in Pawn
    if (piece->getPieceType = PAWN){
        if (abs(endX - startX) == 2){
            peice->performedDoubleMove();
        }
    }
}
}
