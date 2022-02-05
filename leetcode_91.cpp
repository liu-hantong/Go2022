class Solution {
public:  
    int numDecodings(string s) {
      if (s[0] == '0')
        return 0;      
      vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
      int res = numDecode(0, s.size() - 1, dp, s);
      return res;
    }
  
    int numDecode(int i, int j, vector<vector<int>>& dp, string& s) {      
      if (dp[i][j] != -1) {
        return dp[i][j];
      }
      
      int res = 0;
      bool one = false;
      bool two = false;
      
      if (j == i) {
        one = (s[i] >= '1' && s[i] <= '9');
        dp[i][j] = one;
        return one;
      }
      
      two = (s[i] == '1' && s[i + 1] >= '0' && s[i + 1] <= '9') ||
            (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6');
      
      if (j - i == 1) {
        one = (s[i] >= '1' && s[i] <= '9') && (s[i + 1] >= '1' && s[i + 1] <= '9');
        dp[i][j] = one + two;
        return one + two;
      }
      
      one = (s[i] >= '1' && s[i] <= '9');
      
      if (one) {
        res += numDecode(i + 1, j, dp, s);
      }
      
      if (two) {
        res += numDecode(i + 2, j, dp, s);
      }
    
      dp[i][j] = res;
      return res;
    }
};