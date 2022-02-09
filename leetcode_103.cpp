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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      if (root == nullptr)
        return {};
      vector<vector<int>> res;
      deque<TreeNode*> q;
      q.push_front(root);
      bool flag = true;
      while (!q.empty()) {
        int size = q.size();
        vector<int> level_vec;
        if (flag) {
          for (int i = 0; i < size; ++i) {
            TreeNode* cur = q.back();
            q.pop_back();
            level_vec.push_back(cur->val);
            if (cur->left)
              q.push_front(cur->left);
            if (cur->right)
              q.push_front(cur->right);
          }
        }
        else {
          for (int i = 0; i < size; ++i) {
            TreeNode* cur = q.front();
            q.pop_front();
            level_vec.push_back(cur->val);
            if (cur->right)
              q.push_back(cur->right);
            if (cur->left)
              q.push_back(cur->left);
          }
        }
        flag = !flag;
        res.push_back(level_vec);
      }
      return res;
    }
};