class Solution {
public:
    vector<string> generateParenthesis(int n) {
      int init_l = n;
      int init_r = n;
      vector<string> res;
      string cur;
      backtrace(res, cur, init_l, init_r);
      return res;
    }
    
    void backtrace(vector<string>& res, string& cur, int left, int right) {
      if (left == 0 && right == 0) {
        res.push_back(cur);
        return;
      }
      if (left > 0) {
        cur += '(';
        backtrace(res, cur, left - 1, right);
        cur.pop_back();
      }
      if (right > 0 && cur.size() != 0 && left < right) {
        cur += ')';
        backtrace(res, cur, left, right - 1);
        cur.pop_back();
      }    
    }
  
};
