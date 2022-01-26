class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> cur;
      vector<bool> used(nums.size(), false);
      backtrace(res, cur, used, nums);
      return res;
    }
  
    void backtrace(vector<vector<int>>& res, vector<int>& cur, vector<bool>& used, vector<int>& nums) {
      if (cur.size() == nums.size()) {
        res.push_back(cur);
        return;
      }
      for (int i = 0; i < used.size(); ++i) {
        if (used[i] == false) {
          cur.push_back(nums[i]);
          used[i] = true;
          backtrace(res, cur, used, nums);
          cur.pop_back();
          used[i] = false;
        }
      }
    }
};