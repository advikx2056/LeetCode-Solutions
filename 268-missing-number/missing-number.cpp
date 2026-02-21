class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XOR1 = 0;  // XOR of 0..n
        int XOR2 = 0;  // XOR of array elements
        int n = nums.size();

        // XOR of array elements
        for (int i = 0; i < n; i++) {
            XOR2 ^= nums[i];
        }

        // XOR of numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            XOR1 ^= i;
        }

        return XOR1 ^ XOR2;
    }
};
