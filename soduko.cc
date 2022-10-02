#include<iostream>

using namespace std;
const int dim = 9;

bool canplace(int board[][dim], int x, int y, int curnum) {
  for (int i = 0; i < dim; i++) {
    if (board[i][y] == curnum) return false;
    if (board[x][i] == curnum) return false;
  }

  int subboxRow = x - x % 3;
  int subboxCol = y - y % 3;
  for (int i = subboxRow; i < subboxRow + 3; ++i) {
    for (int j = subboxCol; j < subboxCol + 3; ++j) {
      if (board[i][j] == curnum) return false;
    }
  }
  return true;

}

int sudoku(int board[][dim], int x, int y) {
  if (x == dim) {
    return true;
  }
  if (y == dim) {
    return sudoku(board, x + 1, 0);
  }
  if (board[x][y] != 0) {
    return sudoku(board, x, y + 1);
  }
  for (int curnum = 1; curnum <= dim; curnum++) {
    if (canplace(board, x, y, curnum)) {
      board[x][y] = curnum;
      bool isSuccessful = sudoku(board, x, y + 1);
      if (isSuccessful) return true;
      board[x][y] = 0;
    }
  }
  return false;
}

int printBoard(int board[][dim]) {
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int board[][dim] = {
                {5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
  };

  cout << sudoku(board, 0, 0) ? printBoard(board) : "Hey man! get it solved from someone else!";
  
  return 0;
}
