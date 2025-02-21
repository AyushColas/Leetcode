class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int maxSum = nums[0], currentSum = 0;
        for (int num : nums) {
            currentSum = std::max(num, currentSum + num);
            maxSum = std::max(maxSum, currentSum);
        }
        return maxSum;
    }
};
