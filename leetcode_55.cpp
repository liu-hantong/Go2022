class Solution {
public:
    bool canJump(vector<int>& nums) {
      int m = 0;
      for(int i = 0; i < nums.size(); ++i) {        
        if (nums[i] + i >= nums.size() - 1)
          return true;
        else if (nums[i] + i > m) {
          m = nums[i] + i;
        }
        
        if (m < i + 1)
          break;
      }
      if (m >= nums.size() - 1)
        return true;
      else
        return false;
    }
  
  };