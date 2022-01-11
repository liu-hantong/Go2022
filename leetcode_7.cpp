class Solution {
public:
    int reverse(int x) {
      if (x == 0) {
        return 0;
      }
      if (x == -2147483648) {
        return 0;
      }
      int sign = x > 0 ? 1 : -1;
      int x_copy = sign * x;
      unsigned long long res = 0;
      while (x_copy != 0) 
      {
        res = res * 10 + x_copy % 10;
        x_copy = x_copy / 10;
      }
      
      unsigned res_cut = (unsigned)res;      
      int new_sign = (int)(res_cut * sign) > 0 ? 1 : -1;
      
      if ((unsigned long long)res_cut != res || new_sign != sign) {
        return 0;
      }
      return (unsigned)res_cut * sign;
    }
};