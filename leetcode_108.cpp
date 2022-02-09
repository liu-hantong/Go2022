/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return myConvert(0, nums.size() - 1, nums);
    }
  
    TreeNode* myConvert(int l, int r, vector<int>& nums) {
      if (l > r) {
        return nullptr;
      }
      int middle = l + (r - l) / 2;
      TreeNode* cur = new TreeNode(nums[middle]);
      cur->left =  myConvert(l, middle - 1, nums);
      cur->right = myConvert(middle + 1, r, nums);
      return cur;
    }
};