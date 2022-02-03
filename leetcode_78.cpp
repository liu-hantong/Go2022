class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> cur = {};
      backtrace(res, nums, cur, -1);
      return res;
    }
  
    void backtrace(vector<vector<int>> &res, vector<int> &nums, vector<int> &cur, int index) {
      res.push_back(cur);
      for(int i = index + 1; i < nums.size(); ++i) {
        cur.push_back(nums[i]);
        backtrace(res, nums, cur, i);
        cur.pop_back();
      }    
    }
};