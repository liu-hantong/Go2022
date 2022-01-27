class Solution {
public:
    double myPow(double x, int n) {
      if (x == 1.0 || n == 0) {
        return 1.0;
      }
      
      if (x == 0.0) {
        return 0.0;
      }

      int mark = n > 0 ? 1 : -1;
      long long n_copy = (long long)n * mark;
      double res = 1.0;
            
      res = subPow(x, n_copy);  
      
      if (mark == 1) {
        return res;
      }
      else {
        return 1 / res;
      }
    }
  
    double subPow(double x, long long n) {
      long long multi_num = 1; 
      double x_original = x;
      while (multi_num * 2 <= n) {
        x *= x;
        multi_num *= 2;
      }
      
      if (n - multi_num > 0) {
        x *= subPow(x_original, n - multi_num);
      }
      return x;
    }
};