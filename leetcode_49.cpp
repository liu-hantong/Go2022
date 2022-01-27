class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> res;
    
      unordered_map<string, vector<string>> m; 
      
      for(auto& str : strs) {
        string cur = str;
        sort(str.begin(), str.end());
        m[str].push_back(cur);
      }
      
      for(auto it = m.begin(); it != m.end(); ++it) { 
        res.push_back(it->second);
      }
      
      return res;
    }
};