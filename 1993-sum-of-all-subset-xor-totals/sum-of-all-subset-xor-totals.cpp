class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }

private:
    int dfs(const vector<int>& nums, int index, int currXOR) {
        if (index == nums.size())
            return currXOR;
    
        return dfs(nums, index + 1, currXOR ^ nums[index]) + dfs(nums, index + 1, currXOR);
    }
};