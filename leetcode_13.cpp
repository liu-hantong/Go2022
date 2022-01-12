class Solution {
public:
    int r2i(char s) {
      if (s == 'I')
        return 1;
      else if (s == 'V')
        return 5;
      else if (s == 'X')
        return 10;
      else if (s == 'L')
        return 50;
      else if (s == 'C')
        return 100;
      else if (s == 'D')
        return 500;
      else 
        return 1000;    
    }
    
    int romanToInt(string s) {
      int i = 0;
      int res = 0;
      while(1) {
        if (i == s.size()) {
          break;
        }
        if (i + 1 < s.size()) {
          if (s[i] == 'I' && s[i+1] == 'V')
          {res += 4; i += 2;}
          else if (s[i] == 'I' && s[i+1] == 'X')
          {res += 9; i += 2;}
          else if (s[i] == 'X' && s[i+1] == 'L')
          {res += 40; i += 2;}
          else if (s[i] == 'X' && s[i+1] == 'C')
          {res += 90; i += 2;}
          else if (s[i] == 'C' && s[i+1] == 'D')
          {res += 400; i += 2;}
          else if (s[i] == 'C' && s[i+1] == 'M')
          {res += 900; i += 2;}
          else
            res += r2i(s[i++]);
        }
        else {
          res += r2i(s[i++]);
        }
      }
      return res;
    }
};