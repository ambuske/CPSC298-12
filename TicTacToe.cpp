#include <iostream>
#include <tuple>
using namespace std;

class TicTacToeGame {
  public: 
    TicTacToeGame();
    virtual ~TicTacToeGame();
    void Play();
  private:
    void initializeGrid();
    void displayGrid();
    tuple<int, int> findFirstUnoccupiedGridSquare();
    tuple<int, int> promptForGridCordinates();
    bool checkforDraw();
    bool checkForWin();
  private:
    char** pp_cGrid = nullptr;
};
TicTacToeGame::TicTacToeGame() {
  this->pp_cGrid=new char*[3];
  for(int i=0;i<3;i++) {
    pp_cGrid[i]=new char[3];
  }
  initializeGrid();
}
TicTacToeGame::~TicTacToeGame() {
  for(int i=0;i<3;i++) {
    delete[] pp_cGrid[i];
  }
  delete[] pp_cGrid;
  pp_cGrid=nullptr;
}


int main() {
  TicTacToeGame* p_game = new TicTacToeGame();
  p_game->Play();
  delete p_game;
  return 0;
}

void TicTacToeGame::initializeGrid() {
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      this->pp_cGrid[i][j]='~';
    }
  }
}
void TicTacToeGame::displayGrid() {
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      cout<<this->pp_cGrid[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}
void TicTacToeGame::Play() {
  bool bWin = false;
  bool bDraw = false;
  int iRow = 0;
  int jColumn = 0;
  cout<<"Tic Tac Toe"<<endl;
  cout<<endl;
  displayGrid();
  while(!bWin && !bDraw) {
    
    tie(iRow, jColumn) = promptForGridCordinates();
    this->pp_cGrid[iRow][jColumn]='X';
    displayGrid();
    bWin = checkForWin();
    bDraw = checkforDraw();
    
    if(!bWin and !bDraw) {
      tie(iRow, jColumn) = findFirstUnoccupiedGridSquare();
      this->pp_cGrid[iRow][jColumn]='O';
      displayGrid();
      bWin = checkForWin();
      bDraw = checkforDraw();
    }
    if(bDraw && !bWin) {
      cout<<"Draw! "<<endl;
    }
  }
  cout<<"Game over."<<endl;
  return;
}
tuple<int, int> TicTacToeGame::promptForGridCordinates() {
  int iRow = 0;
  int jColumn = 0;
  cout<< "Enter row number: "<<endl;
  cin>>iRow;
  cout<< "Enter column number: "<<endl;
  cin>>jColumn;
  tuple<int,int> tupleCoord = make_tuple(iRow,jColumn);
  return tupleCoord;
}
tuple<int, int> TicTacToeGame::findFirstUnoccupiedGridSquare() {
  int iRowUnoccupied = -1;
  int jColumnUnoccupied = -1;
  bool bFound = false;
  for(int i=0;(i<3) &&(!bFound);i++) {
    for(int j=0;(j<3) &&(!bFound);j++) {
      if(this->pp_cGrid[i][j]=='~') {
        iRowUnoccupied = i;
        jColumnUnoccupied = j;
        bFound = true;
      }
    }
  }
  tuple<int, int> tupleUnOcc(iRowUnoccupied, jColumnUnoccupied);
  return tupleUnOcc;
}
bool TicTacToeGame::checkforDraw() {
  bool bContinue= false;
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      if(this->pp_cGrid[i][j]!='X'&& this->pp_cGrid[i][j]!='O') {
        bContinue = true;
      }
    }

  }
  return !bContinue;
}
bool TicTacToeGame::checkForWin() {
  bool bWin = false;
  for(int i=0;i<3;i++) {
    if(this->pp_cGrid[i][0]!='~'){
      if(this->pp_cGrid[i][0]==this->pp_cGrid[i][1] && this->pp_cGrid[i][0]==this->pp_cGrid[i][2]) {
        bWin = true;
        cout<<"WINNER: "<<this->pp_cGrid[i][0]<<"!"<<endl;
      }
    }
  }
  for(int j=0;j<3;j++) {
    if(this->pp_cGrid[0][j]!='~'){
      if(this->pp_cGrid[0][j]==this->pp_cGrid[1][j]&& this->pp_cGrid[0][j]==this->pp_cGrid[2][j]) {
        bWin = true;
        cout<<"WINNER: "<<this->pp_cGrid[0][j]<<"!"<<endl;
      }
    }
  }
  if(this->pp_cGrid[0][0]!='~'){
    if(this->pp_cGrid[0][0]==this->pp_cGrid[1][1]&& this->pp_cGrid[0][0]==this->pp_cGrid[2][2]) {
      bWin = true;
      cout<<"WINNER: "<<this->pp_cGrid[0][0]<<"!"<<endl;
    }
  }
  if(this->pp_cGrid[0][2]!='~'){
    if(this->pp_cGrid[0][2]==this->pp_cGrid[1][1]&& this->pp_cGrid[0][2]==this->pp_cGrid[2][0]) {
      bWin = true;
      cout<<"WINNER: "<<this->pp_cGrid[0][2]<<"!"<<endl;
    }
  }
  return bWin;
}
