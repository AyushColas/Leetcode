class Solution {
public:
    bool isPowerOfTwo(int num) {
        const int largestPowerOfTwo =1073741824; 
        return num > 0 && largestPowerOfTwo % num == 0;
    }
};