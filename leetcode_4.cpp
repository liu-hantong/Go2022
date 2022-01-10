class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> combine;
      int i = 0;
      int j = 0;
      while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
          combine.push_back(nums1[i]);
          i++;
        }
        else {
          combine.push_back(nums2[j]);
          j++;
        }
      }
      
      if (i == nums1.size()) {
        while (j != nums2.size()) {
          combine.push_back(nums2[j]);
          j++;
        }
      }
      else if (j == nums2.size()) {
        while (i != nums1.size()) {
          combine.push_back(nums1[i]);
          i++;
        } 
      }
      
      int size = combine.size();
      
      if (size == 0) {
        return 0;
      }
      
      if (size % 2 == 0) {
        return (combine[size / 2] + combine[size / 2 - 1]) / 2.0;
      }
      else {
        return combine[size / 2];
      } 
    }
};