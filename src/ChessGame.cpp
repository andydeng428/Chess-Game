#include "ChessGame.h"
#include "Pawn.h"
#include "Rook.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "ChessRuleBook.h"

const int tileSize = 100;

ChessGame::ChessGame() : selected(false), selectedX(-1), selectedY(-1) {
    currentPlayer = Color::WHITE;
}

void ChessGame::startGame() {
    initializeBoard();
}

void ChessGame::initializeBoard() {
    for (int i = 0; i < 8; ++i) {
        board.getPiece(i, 1) = new Pawn(Color::WHITE);
        board.getPiece(i, 6) = new Pawn(Color::BLACK);
    }
    board.getPiece(4, 0) = new King(Color::WHITE);
    board.getPiece(4, 7) = new King(Color::BLACK);
    board.getPiece(0, 0) = new Rook(Color::WHITE);
    board.getPiece(7, 0) = new Rook(Color::WHITE);
    board.getPiece(0, 7) = new Rook(Color::BLACK);
    board.getPiece(7, 7) = new Rook(Color::BLACK);
    board.getPiece(1, 0) = new Knight(Color::WHITE);
    board.getPiece(6, 0) = new Knight(Color::WHITE);
    board.getPiece(1, 7) = new Knight(Color::BLACK);
    board.getPiece(6, 7) = new Knight(Color::BLACK);
    board.getPiece(2, 0) = new Bishop(Color::WHITE);
    board.getPiece(5, 0) = new Bishop(Color::WHITE);
    board.getPiece(2, 7) = new Bishop(Color::BLACK);
    board.getPiece(5, 7) = new Bishop(Color::BLACK);
    board.getPiece(3, 0) = new Queen(Color::WHITE);
    board.getPiece(3, 7) = new Queen(Color::BLACK);

    for (int i = 0; i < 8; ++i) {
        for (int j = 2; j < 6; ++j) {
            board.getPiece(i, j) = nullptr;
        }
    }
}

bool ChessGame::performMove(int startX, int startY, int endX, int endY) {
    if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 || endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
        return false;
    }
    if (!board.isOccupied(startX, startY)) {
        return false;
    }
    Piece* piece = board.getPiece(startX, startY);
    if (!ChessRuleBook::isMoveLegal(piece, board, startX, startY, endX, endY)) {
        return false;
    }
    if (board.isOccupied(endX, endY)) {
        delete board.getPiece(endX, endY);
    }
    board.movePiece(endX, endY, startX, startY);
    return true;
}

bool ChessGame::isCheckmate(Color playerColor) {
    int kingX = -1, kingY = -1;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece* piece = board.getPiece(i, j);
            if (piece != nullptr && piece->getColor() == playerColor && piece->getPieceType() == PieceType::KING) {
                kingX = i;
                kingY = j;
                break;
            }
        }
        if (kingX != -1) break;
    }

    bool kingInCheck = false;
    for (int i = 0; i < 8 && !kingInCheck; ++i) {
        for (int j = 0; j < 8 && !kingInCheck; ++j) {
            if (i == kingX && j == kingY) continue;
            Piece* attacker = board.getPiece(i, j);
            if (attacker != nullptr && attacker->getColor() != playerColor) {
                if (ChessRuleBook::isMoveLegal(attacker, board, i, j, kingX, kingY)) {
                    kingInCheck = true;
                }
            }
        }
    }

    if (!kingInCheck) {
        return false;
    }

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int newX = kingX + dx;
            int newY = kingY + dy;
            if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
                if (!board.isOccupied(newX, newY) || board.getPiece(newX, newY)->getColor() != playerColor) {
                    if (!isKingInCheck(playerColor, newX, newY)) {
                        return false;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i == kingX && j == kingY) continue;
            Piece* piece = board.getPiece(i, j);
            if (piece != nullptr && piece->getColor() == playerColor) {
                for (int x = 0; x < 8; ++x) {
                    for (int y = 0; y < 8; ++y) {
                        if (x == i && y == j) continue;
                        if (ChessRuleBook::isMoveLegal(piece, board, i, j, x, y)) {
                            Piece* capturedPiece = board.getPiece(x, y);
                            board.movePiece(x, y, i, j);
                            if (!isKingInCheck(playerColor, kingX, kingY)) {
                                board.movePiece(i, j, x, y);
                                board.movePiece(x, y, i, j);
                                return false;
                            }
                            board.movePiece(i, j, x, y);
                            board.movePiece(x, y, i, j);
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool ChessGame::isStalemate(Color currentPlayer, const Board& board) {
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if (board.isOccupied(x, y) && board.getPiece(x, y)->getColor() == currentPlayer) {
                for (int newX = 0; newX < 8; ++newX) {
                    for (int newY = 0; newY < 8; ++newY) {
                        if (ChessRuleBook::isMoveLegal(board.getPiece(x, y), board, x, y, newX, newY)) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool ChessGame::isGameEnded(Color currentPlayer, const Board& board) {
    int totalPieces = 0;
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if (board.isOccupied(x, y)) {
                totalPieces++;
            }
        }
    }
    if (totalPieces <= 2) {
        return true;
    }
    if (ChessRuleBook::isCheckmate(currentPlayer, board)) {
        return true;
    }
    if (ChessRuleBook::isStalemate(currentPlayer, board)) {
        return true;
    }
    return false;
}

void ChessGame::drawBoard(sf::RenderWindow &window) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));
            tile.setPosition(i * tileSize, j * tileSize);
            if ((i + j) % 2 == 0) {
                tile.setFillColor(sf::Color::White);
            } else {
                tile.setFillColor(sf::Color::Black);
            }
            window.draw(tile);
            if (board.isOccupied(i, j)) {
                Piece* piece = board.getPiece(i, j);
                sf::CircleShape pieceShape(tileSize / 2 - 10);
                pieceShape.setPosition(i * tileSize + 10, j * tileSize + 10);
                pieceShape.setFillColor(piece->getColor() == Color::WHITE ? sf::Color::Yellow : sf::Color::Red);
                window.draw(pieceShape);
            }
        }
    }
}

void ChessGame::handleClick(int x, int y) {
    if (!selected) {
        if (board.isOccupied(x, y) && board.getPiece(x, y)->getColor() == currentPlayer) {
            selected = true;
            selectedX = x;
            selectedY = y;
        }
    } else {
        if (performMove(selectedX, selectedY, x, y)) {
            if (isGameEnded(currentPlayer, board)) {
                // handle game end logic
            } else {
                currentPlayer = (currentPlayer == Color::WHITE) ? Color::BLACK : Color::WHITE;
            }
        }
        selected = false;
    }
}
