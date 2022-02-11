class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      if (numRows == 1)
        return {{1}};
      else {
        vector<vector<int>> res = generate(numRows - 1);
        vector<int> next;
        int row = res.size() - 1;
        int rowSize = res[row].size();
        next.push_back(1);
        for(int i = 0; i < rowSize - 1; ++i) {
          next.push_back(res[row][i] + res[row][i + 1]);
        }
        next.push_back(1);
        res.push_back(next);
        return res;
      }
    }
};
