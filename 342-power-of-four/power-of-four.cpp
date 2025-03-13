class Solution {
public:
    bool isPowerOfFour(int num) {
        const int largestPowerOfFour = 1073741824; 
        
        return num > 0 && (largestPowerOfFour % num == 0) && (num & (num - 1)) == 0 && (num % 3 == 1);
        
    }
};