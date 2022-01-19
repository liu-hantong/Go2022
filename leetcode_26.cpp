class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.size() == 0) {
        return 0;
      }
      int last = 1;
      for(int i = 1; i < nums.size(); ++i) {
        while(i < nums.size() && nums[i - 1] == nums[i])
          i++;
        if (i < nums.size()) {
          nums[last++] = nums[i];
        }
      }
      return last;
    }
};