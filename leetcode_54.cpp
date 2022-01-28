class Solution {
public:
    typedef enum e_direction {
      right = 0,
      down,
      left,
      up
    } direction;
  
    unordered_map<direction, vector<int>> dr_offset = {
      {right, {0, 1}},
      {down, {1, 0}},
      {left, {0, -1}},
      {up, {-1, 0}}
    };
    
    unordered_map<direction, direction> dr_change = {
      {right, down},
      {down, left},
      {left, up},
      {up, right}
    };
  
    bool valid(vector<vector<int>>& matrix, vector<int>& pos) {
      int x = pos[0];
      int y = pos[1];
      if (x >= matrix.size() || x < 0) {
        return false;
      }
      if (y >= matrix[0].size() || y < 0) {
        return false;
      }
      if (matrix[x][y] == -1000) {
        return false;
      }
      return true;
    }
  
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> res;
      direction d = right;
      int matrix_size = matrix.size() * matrix[0].size();
      vector<int> p = {0, -1};
      while (res.size() < matrix_size) {
        vector<int> n_c = dr_offset[d];
        vector<int> n_p(2);
        n_p[0] = p[0] + n_c[0];
        n_p[1] = p[1] + n_c[1];
        if (valid(matrix, n_p)) {
          res.push_back(matrix[n_p[0]][n_p[1]]);
          matrix[n_p[0]][n_p[1]] = -1000;
          p = n_p;
        } 
        else {
          d = dr_change[d];
        }
      }     
      return res;
    }
};