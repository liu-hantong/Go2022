class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int size = digits.size();
        int pos = size - 1;
        while (carry == 1) {
            if (pos < 0) {
                vector<int> res(size + 1);
                res[0] = 1;
                for(int i = 0; i < size; ++i)
                    res[i + 1] = digits[i];
                return res;
            }
            else {
                int res = digits[pos] + 1;
                digits[pos] = res % 10;
                carry = res / 10;
                pos--;
            }
        }
        return digits;
    }
};