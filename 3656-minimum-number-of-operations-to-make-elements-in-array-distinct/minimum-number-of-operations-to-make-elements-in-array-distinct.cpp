class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        for (int ops = 0; ops <= (n + 2) / 3; ++ops) {
            unordered_set<int> seen;
            bool allDistinct = true;
            for (int i = ops * 3; i < n; ++i) {
                if (seen.count(nums[i])) {
                    allDistinct = false;
                    break;
                }
                seen.insert(nums[i]);
            }
            if (allDistinct) return ops;
        }
        return (n + 2) / 3; 
    }
};
