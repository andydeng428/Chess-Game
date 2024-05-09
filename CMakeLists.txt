cmake_minimum_required(VERSION 3.26)
project(Chess_Andy)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
add_executable(ChessGame
        src/Piece.cpp
        src/Pawn.cpp
        src/Rook.cpp
        src/Knight.cpp
        src/Bishop.cpp
        src/Queen.cpp
        src/King.cpp
        src/Board.cpp
        src/ChessRuleBook.cpp
        src/ChessGame.cpp
)
