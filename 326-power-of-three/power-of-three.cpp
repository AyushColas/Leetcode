class Solution {
public:
    bool isPowerOfThree(int num) {
        const int largestPowerOfThree = 1162261467; 
        return num > 0 && largestPowerOfThree % num == 0;
    }
};