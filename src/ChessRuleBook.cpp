#include "ChessRuleBook.h"


bool ChessRuleBook::isMoveLegal(Piece* piece, const Board board, int startX, int startY, int endX, int endY){
    PieceType type = piece->getPieceType();
    Color color = piece->getColor();

    switch (type) {
        case PieceType::PAWN:
            return isMoveLegalForPawn(board, color, startX, startY, endX, endY);
        case PieceType::KNIGHT:
            return isMoveLegalForKnight(board, color, startX, startY, endX, endY);
        case PieceType::BISHOP:
            return isMoveLegalForBishop(board, color, startX, startY, endX, endY);
        case PieceType::ROOK:
            return isMoveLegalForRook(board, color, startX, startY, endX, endY);
        case PieceType::QUEEN:
            return isMoveLegalForQueen(board, color, startX, startY, endX, endY);
        case PieceType::KING:
            return isMoveLegalForKing(board, color, startX, startY, endX, endY);
        default:
            return false;
    }
}

bool ChessRuleBook::isMoveLegalForPawn(const Board board, Color color, int startX, int startY, int endX, int endY){
    int direction;
    if (color == Color::WHITE){
        direction = 1;
    } else {
        direction = -1;
    }
    //check if forward move is possible
    if ((startY + direction == endY)&&(startX == endX)&&(!board.isOccupied(endX, endY)){
        return true;
    }
    //check for double move start
    if ((startY + 2 * direction == endY)&&(startY == ((color == Color::WHITE) ? 1:6))&&(!board.isOccupied(endX, endY)){
        return true;
    }
    //check for move capture
    if ((abs(startX - endX) == 1)&&(startY + direction == endY)){
        //check if the destination square is occupied by an opoosite color's piece
        Piece* destinationPiece = board.getPiece(endX, endY);
        if (destinationPiece != nullptr && destinationPiece->getColor() != color){
            return true;
        }
    }
}

bool ChessRuleBook::isMoveLegalForKnight(const Board board, Color color, int startX, int startY, int endX, int endY){
    int xDir = abs(endX - startX);
    int yDir = abs(endY - startY);

    if ((xDir == 1 && yDir == 2) || (xDir == 2 && yDir == 1)){
        //check if end cords is occupied by peice of same color
        Piece* destinationPiece = board.getPiece(endX, endY);
        if (destinationPiece == nullptr || destinationPiece->getColor() != color){
            return true;
        }
    }
    return false;
}

bool ChessRuleBook::isMoveLegalForKing(const Board board, Color color, int startX, int startY, int endX, int endY){
    int xDir = abs(endX - startx);
    int yDir = abs(endY - startY);

    if ((xDir <= 1) && (yDir <= 1)){
        //check if end cord occupied by peice of same color
        Piece* destinationPiece = board.getPiece(endX, endY);
        if (destinationPiece == nullptr || destinationPiece->getColor() != color){
            return true;
        }
    }
}

bool ChessRuleBook::isMoveLegalForRook(const Board board, Color color, int startX, int startY, int endX, int endY){
    int xDiff = abs(endX - startX);
    int yDiff = abs(endY - startY);
    //check if peice moving on columns and rows
    if (!(xDiff == 0 || yDiff == 0)){
        return false;
    }
    int xDir;
    if (endX - startX > 0){
        xDir = 1;
    } else if (endX - startX < 0){
        xDir = -1;
    } else{
        xDir = 0;
    }
    int yDir;
    if (endY - startY > 0){
        yDir = 1;
    } else if (endY - startY < 0){
        yDir = -1;
    } else{
        yDir = 0;
    }
    int x = startX + xDir;
    int y = startY + yDir;
    while (x != endX || y != endY){
        if (board.isOccupied(x, y)){
            return false;
        }
        x += xDir;
        y += yDir;
    }
    //check if end cord occupied by peice of same color
    if (board.isOccupied(endX, endY)) {
        Piece* piece = board.getPiece(endX, endY);
        if (piece->getColor() == color){
            return false;
        }
    }
}

bool ChessRuleBook::isMoveLegalForQueen(const Board board, Color color, int startX, int startY, int endX, int endY){
    int xDir = endX - startX;
    int yDir = endY - startY;

    //check if the move is on straight line
    if (xDir == 0 || yDir == 0 || abs(xDir) == abs(yDir)){
        //check if there are any pieces blocking the path
        int dx = (xDir > 0) - (xDir < 0);
        int dy = (yDir > 0) - (yDir < 0);
        int steps = max(abs(xDir), abs(yDir)) - 1;
        int currentX = startX + dx;
        int currentY = startY + dy;
        for (int i = 0; i < steps; ++i) {
            if (board.isOccupied(currentX, currentY)){
                return false;
            }
            currentX += dx;
            currentY += dy;
        }
        //check if end cord occupied by peice of same color
        Piece* destinationPiece = board.getPiece(endX, endY);
        if (destinationPiece == nullptr || destinationPiece->getColor() != color){
            return true;
        }
    }

    return false;
}

bool ChessRuleBook::isMoveLegalForBishop(const Board board, Color color, int startX, int startY, int endX, int endY){
    int xDir = endX - startX;
    int yDir = endY - startY;

    // check if diagonal
    if (abs(xDir) == abs(yDir)) {
        int dx = (xDir > 0) - (xDir < 0);
        int dy = (yDir > 0) - (yDir < 0);
        //check if path is blockled
        int steps = abs(xDir) - 1;
        int currentX = startX + dx;
        int currentY = startY + dy;
        for (int i = 0; i < steps; ++i) {
            if (board.isOccupied(currentX, currentY)){
                return false;
            }
            currentX += dx;
            currentY += dy;
        }
        //check if end cord occupied by peice of same color
        Piece* destinationPiece = board.getPiece(endX, endY);
        if (destinationPiece == nullptr || destinationPiece->getColor() != color){
            return true;
        }
    }

    return false;
}

