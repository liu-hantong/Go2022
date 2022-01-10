class Solution {
public:
    string longestPalindrome(string s) {
      int size = s.size(); 
      vector<vector<bool>> vec(size, vector<bool>(size, false));
      for (int i = 0; i < size; ++i) {
        vec[i][i] = true;
      }
      vector<int> a = {0, 0};
      for (int i = 1; i < size; ++i)
        for (int j = 0; j + i < size; ++j)
        {
          int left = j;
          int right = j + i;
          if (left + 1 <= right - 1) {
            if (s[left] == s[right] && vec[left+1][right -1])
            {
              vec[left][right] = true;
            }
          }
          else {
            if (s[left] == s[right]) {
              vec[left][right] = true;
            }
          }
          if (vec[left][right] == true && right - left > a[1] - a[0]) {
            a[0] = left;
            a[1] = right;
          }
        }
      return s.substr(a[0], a[1] - a[0] + 1);
    }
};