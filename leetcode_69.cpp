class Solution {
public:
    int mySqrt(int x) {
      int res = 0;
      if (x == 0) {
        return 0;
      }   
      else if (x == 1 || x == 2) {
        return 1;
      }
      else {
        int left = 1;
        int right = x / 2;
        while (left <= right) {
          long long m = left + (right - left) / 2;
          long long plus = m * m;
          if (m * m <= x) {
            res = m;
            left = m + 1;
          }
          else if (m * m > x) {
            right = m - 1;
          }
          else {
            return m;
          }
        }
      }
      return res;
    }
};