class Board{
public:
  bool isOccupied(int x, int y);
  Piece getPiece(int x, int y);
  void movePiece();
private:
  Piece* board[8][8];
}

Board::Board(){
  for (int i = 0 ; i < 8 ; i++){
    for (int k = 0 ; k < 8 ; k++){
      board[i][k] = nullptr
    }
  }
}

bool Board::isOccupied(int x, int y){
  return board[x][y] != nullptr;
}

Piece* Board::getPiece(int x, int y) { //get access to peice object
    return board[x][y];
}

void Board::movePiece(Board& board, int endX, int endY, int startX, int startY){
  // check if start location has piece
  if (!isOccupied(startX, startY)){
    return;
  }
  //get pointer to piece
  Piece* piece = board.getPiece(x, y);
  //determine if move legal
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
}

Y
8 ■ □ ■ □ ■ □ ■ □ 
7 □ ■ □ ■ □ ■ □ ■ 
6 ■ □ ■ □ ■ □ ■ □ 
5 □ ■ □ ■ □ ■ □ ■ 
4 ■ □ ■ □ ■ □ ■ □ 
3 □ ■ □ ■ □ ■ □ ■ 
2 ■ □ ■ □ ■ □ ■ □ 
1 □ ■ □ ■ □ ■ □ ■  
  1 2 3 4 5 6 7 8 X





////////////////////////////////////////////////////

class Piece{
public:
  Peice (Color color, PieceType type)

// get the private variables (position)
  int getX();
  int getY();

// get the protected variables
  Color getColor{
		return color;
  }
  PieceType getPieceType{
    return type;
  }

protected:
  Color getColor;
  PieceType getType;
private:
  int x;
  int y;
}

/////////////////////////////////

//Peices 
//pawns
class Pawn :: public Peice{
public:
  Pawn(Color color){
    color = color;
    type = PieceType::PAWN:
  }
}

/////////////////////enum classes
enum class Color {
    WHITE,
    BLACK
};

enum class PieceType {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};








////////////////////////////////////////////////////////////
class ChessRuleBook {
public:
  //write a funcion that takes in board,
    bool isMoveLegal(Piece* piece, const Board board, int startX, int startY, int endX, int endY);
private:
    bool isMoveLegalForPawn(const Board board, color color, int startX, int startY, int endX, int endY);
};

bool ChessRuleBook::isMoveLegal(Piece* piece, const Board board, int startX, int startY, int endX, int endY){
  PieceType type = piece->getType();
  // Color color = piece->getColor();

}

bool ChessRuleBook::isMoveLegalForPawn(const Board board, color color, int startX, int startY, int endX, int endY){
	int direction;
	if (color == Color::WHITE) {
    direction = 1;
	} else {
    direction = -1;
	}
  //check if forward move is possible
	if ((startY + direction == endY) && (startX == endX) && (!board.isOccupied(endX, endY)) {
    return true;
	}
	//check for double move start
	if ((startY + 2 * direction == endY) && (startY == ((color == Color::WHITE) ? 1 : 6)) && (!board.isOccupied(endX, endY)) {
    return true;
	}
  //check for move capture	
	if ((abs(startX - endX) == 1) && (startY + direction == endY) && (board.isOccupied(endX, endY)) {
    return true; 
	}
  return false;
}

bool ChessRuleBook::isMoveLegalForKnight(const Board board, color color, int startX, int startY, int endX, int endY){
  int xDir = abs(endX - startx);
  int yDir = abs(endY - startY);

  if ((xDir == 1 && yDir == 2) || (xDir == 2 && yDir == 1)){
    return true;
  }
  return false;
}

bool ChessRuleBook::isMoveLegalForKing(const Board board, color color, int startX, int startY, int endX, int endY){
  int xDir = abs(endX - startx);
  int yDir = abs(endY - startY);
	
  if ((xDir <= 1) && (yDir <= 1)){
    return true;
  }
  return false;
}
      
bool ChessRuleBook::isMoveLegalForRook(const Board board, color color, int startX, int startY, int endX, int endY){
  int xDir = abs(endX - startx);
  int yDir = abs(endY - startY);
  
  if (xDir == 0){
    
  }
}








/////////////////////
class ChessGame{
public:
private:
}








