class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      unordered_map<int, int> m;
      vector<int> res(2);
      for (int i = 0; i < numbers.size(); ++i) {
        if (m.find(target - numbers[i]) != m.end()) {
          res[0] = m[target - numbers[i]] + 1;
          res[1] = i + 1;
        }
        m[numbers[i]] = i;
      }
      return res;
    }
};