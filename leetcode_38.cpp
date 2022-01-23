class Solution {
public:
    string countAndSay(int n) {
      if (n == 1) {
        return "1";
      }
      else {
        string prev = countAndSay(n - 1);
        string res = "";
        int i = 0;
        while (i < prev.size()) {
          int count = 1;
          char c = prev[i];
          while (i + 1 != prev.size() && prev[i + 1] == c) {
            count++;
            i++;
          }
          res += to_string(count);
          res += c;
          i++;
        }
        return res;
      }
    }
};