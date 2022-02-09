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
    int md = 0;
    int maxDepth(TreeNode* root) {
      findMaxDepth(root, 0);
      return md;
    }
    
    void findMaxDepth(TreeNode* root, int curDepth) {
      if (curDepth > md) {
        md = curDepth;
      }
      
      if (root == nullptr) {
        return;
      }
      
      findMaxDepth(root->left, curDepth + 1);
      findMaxDepth(root->right, curDepth + 1);
    }
};