class Solution {
public:
    int divide(int dividend, int divisor) {
      if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
      } 
      int negatives = 2;
      if (dividend > 0) {
        negatives--;
        dividend = -dividend;
      }
      if (divisor > 0) {
        negatives--;
        divisor = -divisor;
      }
      
      int quotient = 0;
      while (dividend - divisor <= 0) {
        dividend -= divisor;
        quotient--;
      }
      
      if (negatives != 1) {
        return -quotient;
      }
      
      return quotient;
    }
};
