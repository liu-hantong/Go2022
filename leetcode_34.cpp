class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      if (nums.size() == 0) {
        return {-1, -1};
      }
      
      int l_b = -1;
      int r_b = -1;
      
      int l = 0;
      int r = nums.size() - 1;
      while (l <= r) {
        int m = l + (r - l) / 2;
        if ((nums[m] == target && m == 0)
           || (nums[m] == target && m != 0 && nums[m - 1] != target)) {
          l_b = m;
          break;
        }
        else if (nums[m] >= target) {
          r = m - 1;
        }
        else {
          l = m + 1;
        }
      }
      
      l = 0;
      r = nums.size() - 1;
      while (l <= r) {
        int m = l + (r - l) / 2;
        if ((nums[m] == target && m == nums.size() - 1)
           || (nums[m] == target && m != nums.size() && nums[m + 1] != target)) {
          r_b = m;
          break;
        }
        else if (nums[m] <= target) {
          l = m + 1;
        }
        else {
          r = m - 1;
        }
      }

      return {l_b, r_b};
    }
};