// Suduko Solver In c++ Using Backtracking Principle
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;


#define ll long long
#define endl "\n"
#define all(v) (v).begin(),(v).end()
#define rep(i,x,y) for(int i=x; i<=y; i++)
const int mod = 1e9 + 7;


const int n = 9;


bool nowvalid(int row, int col , vector<vector<int>> & board, int letter) {
  for (int k = 0 ; k < 9; k++)
    if (board[row][k] == letter || board[k][col] == letter || board[3 * (row / 3) + k / 3][3 * (col / 3) + k % 3] == letter)
      return false;

  return true;
}

bool solve( vector<vector<int>> & board ) {

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 0) {
        for (int k = 1; k <= 9 ; k++) {
          if (nowvalid( i, j, board, k)) {
            board[i][j] = k;
            if ( solve(board) == true)
              return true;
            else  board[i][j] = 0;

          }
        }
        return false;
      }
    }
  }
  return true;
}


void solveSudoku(vector<vector<int>>& board) {
  solve(board);

}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  vector<vector<int>> board(9, vector<int>(9));
  rep(i, 0, 8)
  rep(j, 0, 8)cin >> board[i][j];
  solveSudoku(board);
  int numofzero = 0;
  rep(i, 0, 8)
  rep(j, 0, 8) if (!board[i][j])numofzero++;

  if (numofzero) {
    cout << " NO SOLUTION" << endl;

  }
  else {
    rep(i, 0, 8) {
      rep(j, 0, 8) {
        cout << board[i][j] << " ";
      }
      cout << endl;
    }
  }
}




