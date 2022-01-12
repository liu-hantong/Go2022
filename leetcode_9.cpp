class Solution {
public:
    bool isPalindrome(int x) {
      int x_copy = x;
      if (x < 0) {
        return false;
      }
      else if (x == 0) {
        return true;
      }
      unsigned long long y = 0;
      while (x != 0) {
        y = y * 10 + x % 10;
        x = x / 10;
      }
      if ((int)y == x_copy) {
        return true;
      }
      else {
        return false;
      }
    }
};