class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if (strs.size() == 1) {
        return strs[0];
      }
      if (strs[0].size() == 0) {
        return "";
      }
      int i = 0;
      for (; i < strs[0].size(); ++i) {
        char cur = strs[0][i];
        for (int j = 1; j < strs.size(); ++j) {
          if (strs[j][i] != cur) {
            return strs[0].substr(0, i);
          } 
        }
      }
      if (i == strs[0].size())
        return strs[0];
      return "";
    }
};