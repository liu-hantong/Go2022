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
    bool isSymmetric(TreeNode* root) {
      return checkEqual(root->left, root->right);  
    }
  
    bool checkEqual(TreeNode* l, TreeNode* r) {
      if (l == nullptr && r == nullptr)
        return true;
      if (l == nullptr || r == nullptr)
        return false;
      return checkEqual(l->left, r->right) 
        && l->val == r->val 
        && checkEqual(l->right, r->left);
    }
};