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
    vector<int> pre;
    vector<int> in;
  
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      pre = preorder;
      in = inorder;
      return myBuild(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode* myBuild(int p1, int p2, int i1, int i2) {
      if (p1 > p2 || i1 > i2)
        return nullptr;
      int middle = pre[p1];
      cout << middle << endl;
      TreeNode* cur = new TreeNode(middle);
      int curPos = i1;
      for(int i = i1; i <= i2; ++i) {
        if (in[i] == middle) {
          curPos = i;
          break;
        }
      }
      curPos = curPos - i1;
      cur->left = myBuild(p1 + 1, p1 + curPos, i1, i1 + curPos - 1);
      cur->right = myBuild(p1 + curPos + 1, p2, i1 + curPos + 1, i2);
      return cur;
    }
  
};