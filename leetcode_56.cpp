class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      
      sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
        return a[0] < b[0];
      });
      
      cout << intervals[0][0] << endl;
      
      vector<vector<int>> output;
      int i = 0;
      while (i < intervals.size()) {  
        int j = i + 1;
        int start = intervals[i][0];
        int end = intervals[i][1];
        
        while (j < intervals.size() && intervals[j][0] <= end) {
          end = max(intervals[j][1], end);
          j++;
        }
        
        output.push_back({start, end});
        i = j;  
      }
      return output;
    }
};