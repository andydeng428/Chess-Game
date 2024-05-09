<!-- ABOUT THE PROJECT -->
# Chess Game

## About the Project

I developed this chess game project as practice to improve my coding skills in C++ and practice object-oriented programming principles. The primary objective was to reinforce my understanding of fundamental concepts of OOP while also adhering to good coding practices such as DRY and SOLID. Throughout the development process, I strived to maintain clean, readable code and ensure that I implimented the essential object-oriented coding concepts like abstraction, encapsulation, and inheritance.

![image](https://github.com/andydeng428/Chess-Game/assets/156530133/7e28e8bd-22a3-4cfe-ac06-69983b6bc138)


## Structure

This project I focused heavily on modulating each entity of chess in a way that was logically, simple to read and easy to maintain. This is how I ultimately decided to structure the game:
* **Board class** - This class represents the board, a 8x8 matrix and allows manipulation of pieces on the board 
* **Piece class** - Parent class where the peices inherit from which serves the basic member functions and variables for any chess peice such as x y cords, color, and piece type
  * **Pawn class** - The pawn inherits from the Piece class, and has its own functionalities such as double moving for first move
  * **Rook class** - Same as pawn...
  * **Knight class** 
  * **Bishop class**
  * **King class**
  * **Queen class**
* **ChessRuleBook class** - This class I decided to act as an actual rulebook, it contains all the functions that verifies if a move performed is legal or not. I made this to be a "static class", allowing other functions to call upon its rules without having to instantiate the class. This keeps all the functions that verifies move legality in one place, allowing it to be easier to generate all legal moves
* **ChessGame class** - This is the heart of the chess game, it instantiate all of the objects and sets up the board, as well as operating the gameloop and checks for checkmate and stalemate as well as keeping track of various other important details of chess

