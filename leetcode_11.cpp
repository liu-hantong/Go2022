class Solution {
public:
    int maxArea(vector<int>& height) {
      if(height.size() == 2) {
        return min(height[0], height[1]);
      }
      int left = 0;
      int right = height.size() - 1;
      int max_area = 0;
      while (left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;
        if (h * w > max_area) {
          max_area = h * w;
        }
        if (height[left] < height[right]) {
          left++;
        }
        else {
          right--;
        }
      }
      return max_area;
    }
};