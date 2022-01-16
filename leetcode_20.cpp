class Solution {   
public:
    unordered_map<char, char> m = {
      {'}', '{'},
      {')', '('},
      {']', '['}
    };
    
    bool isValid(string s) {
      if(s.size() % 2 == 1) {
        return false;
      }
      stack<char> stk;
      for (char c : s) {
        if (c == '(' || c =='[' || c == '{') {
          stk.push(c);  
        }
        else {
          if (stk.size() == 0 || m[c] != stk.top()) {
            return false;
          }
          else {
            stk.pop(); 
          }      
        }
      }
      return stk.empty();
    }
};