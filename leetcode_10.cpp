class Solution {
public:  
    bool isMatch(string s, string p) {
      int m = s.size();
      int n = p.size();

      vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
      dp[0][0] = true;
      
      
      for(int j = 2; j <= n; j += 2) {
        if(p[j - 1] == '*' && dp[0][j - 2])
          dp[0][j] = true;
      }

      for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
          char cur_s = s[i - 1];
          char cur_p = p[j - 1];
          if ( cur_s == cur_p || cur_p == '.') {
            dp[i][j] = dp[i - 1][j - 1];
          }
          else if (cur_p == '*') {
            char cur_p = p[j - 2];
            if (cur_p != '.' && cur_p != cur_s) {
              dp[i][j] = dp[i][j - 2];
            }
            else {
              dp[i][j] = (dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j]);
            }
          }
        }
      }
        
      return dp[m][n];
    }
};