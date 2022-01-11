class Solution {
public:
    bool invalid(char a) {
      if (a == '.') {
        return true;
      }
      else if (a >= 'a' && a <= 'z') {
        return true;
      }
      else if (a >= 'A' && a <= 'Z') {
        return true;
      }
      return false;
    }
    
    bool isDigit(char a) {
      return (a >= '0' && a <= '9');
    }
  
    int myAtoi(string s) {
      if (s.size() == 0)
        return 0;
      long long ma = 2147483647;
      long long mi = -2147483648;
      unsigned long long res = 0;
      long long ret = 0;
      int i = 0;
      int sign = 0;
      while(1) {
        if (i >= s.size()) {
          break;
        }
        if (sign == 0 && s[i] == ' ') {
          while (i < s.size()) {
            if (s[i] == ' ') {
              i++;
            }
            else {
              break;
            }
          }
        }
        if (invalid(s[i])) {
          break;
        }
        if ((s[i] == '-' || s[i] == '+') && sign != 0) {
          break;
        }
        if (i - 1 >= 0 && s[i] == ' ' && isDigit(s[i-1])) {
          break;
        }
        if (sign != 0 && !isDigit(s[i])) {
          break;
        }
        if (s[i] == '+') {
          sign = 1;
        }
        else if (s[i] == '-') {
          sign = -1;
        }
        else if (isDigit(s[i]) && sign == 0) {
          sign = 1;
        }
        if(isDigit(s[i])) {
          res = res * 10 + s[i] - '0';
          ret = res * sign;
          if (ret > ma) {
            ret = ma;
            break;
          }
          else if (ret < mi) {
            ret = mi;
            break;
          }
        }
        i++;
      }
      return ret;
    }
};