class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < board[0].size(); ++j) {
          bool res = backtrace(board, word, i, j, 0);
          if (res)
            return true;
        }
      return false;
    }
  
    bool backtrace(vector<vector<char>>& board, string &word, int i, int j, int p) {
      if (p == word.size())
        return true;
      if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
        return false;
      if (board[i][j] == '0')
        return false;
      if (board[i][j] == word[p]) {
        board[i][j] = '0';
        bool left = backtrace(board, word, i, j - 1, p + 1);  
        if (left)
          return true;
        bool right = backtrace(board, word, i, j + 1, p + 1);  
        if (right)
          return true;
        bool down = backtrace(board, word, i - 1, j, p + 1);  
        if (down)
          return true;
        bool up = backtrace(board, word, i + 1, j, p + 1);  
        if (up)
          return true;
        board[i][j] = word[p];
      }
      return false;
    }
};