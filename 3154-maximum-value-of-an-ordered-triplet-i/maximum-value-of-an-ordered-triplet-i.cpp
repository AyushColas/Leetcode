class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxValue = 0;

        int maxPrefix = nums[0];
        vector<int> maxSuffix(n, 0);
        
        maxSuffix[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; --i) {
            maxSuffix[i] = max(maxSuffix[i + 1], nums[i]);
        }

        for (int j = 1; j < n - 1; ++j) {
            maxValue = max(maxValue, (long long)(maxPrefix - nums[j]) * maxSuffix[j + 1]);
            maxPrefix = max(maxPrefix, nums[j]);
        }

        return maxValue;
    }
};