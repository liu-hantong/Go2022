class Solution {
public:
    int strStr(string haystack, string needle) {     
      int res = -1;
      for(int i = 0; i <= (int)haystack.size() - (int)needle.size(); ++i) {
        int j = i;
        for(; j < haystack.size(); ++j) {
          if (j - i != needle.size() && haystack[j] == needle[j - i])
            continue;
          else
            break;
        }
        if (j - i == needle.size())
          return i;
      }
      return res;
    }
};