class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      vector<vector<char>> check(9 * 3, vector<char>(10, false));
      for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j) {
          char c = board[i][j];
          if (!isdigit(c)) {
            continue;
          }
          int d = c - '0';
          
          if (check[i][d]) {
            return false;
          }
          else {
            check[i][d] = true;
          }
          
          if (check[9 + j][d]) {
            return false;
          }  
          else {
            check[9 + j][d] = true;
          }
        
          int p = i / 3 * 3 + j / 3;
          int p_ = p + 2 * 9;
          if (check[p_][d]) {
            return false;
          }  
          else {
            check[p_][d] = true;
          }
        }
      return true;
    }
};