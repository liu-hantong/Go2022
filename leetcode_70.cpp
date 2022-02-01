class Solution {  
public:
    int climbStairs(int n) {
      vector<int> dp(n + 1, 0);
      return cs(dp, n);
    }
  
    int cs(vector<int>& dp, int n) {
      if (n == 1)
        return 1;
      else if (n == 2)
        return 2;
      else {
        int res1 = dp[n - 1];
        int res2 = dp[n - 2];
        if (res1 == 0) {
          res1 = cs(dp, n - 1);
          dp[n - 1] = res1;
        }
        if (res2 == 0) {
          res2 = cs(dp, n - 2);
          dp[n - 2] = res2;
        }
        return res1 + res2;
      }        
    }
};