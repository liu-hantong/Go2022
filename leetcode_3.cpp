class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if (s.size() == 0) {
        return 0;
      }
      int res = 1;
      vector<int> lastPos(255, -1);
      vector<int> endLongest(s.size());
    
      lastPos[s[0]] = 0;
      endLongest[0] = 1;
      
      for (int i = 1; i < s.size(); ++i) {
        char cur = s[i];
        if (i - endLongest[i - 1] > lastPos[cur]) {
          endLongest[i] = endLongest[i-1] + 1;
        }
        else {
          endLongest[i] = i - lastPos[cur];
        }
        lastPos[cur] = i;
        if (endLongest[i] > res) {
          res = endLongest[i];  
        }
      }
      return res;
    }
};  