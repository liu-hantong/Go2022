class Solution {
public:
      map<char, string> ref = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
      };

    vector<string> res;
  
    vector<string> letterCombinations(string digits) {
      if (digits.size() == 0)
        return vector<string>();
      string cur = "";
      backtrace(digits, cur, 0);
      return res;
    }
  
    void backtrace (string& digits, string& cur, int i) {
      if (cur.size() == digits.size()) {
        res.push_back(cur);
      }
      for (int j = 0; j < ref[digits[i]].size(); ++j) {
        cur.push_back(ref[digits[i]][j]);
        backtrace(digits, cur, i + 1);
        cur.pop_back();
      }
    }
};