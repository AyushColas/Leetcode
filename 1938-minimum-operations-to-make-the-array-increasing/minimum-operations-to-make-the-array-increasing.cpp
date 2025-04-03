class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count =0;
        if(nums.size() == 1) return 0;
        
        for(int i =0; i<nums.size()-1; i++)
        {
            if(nums[i+1] <= nums[i])
            {
            int temp = nums[i+1];
            nums[i+1] = nums[i]+1;
            count+= nums[i+1]-temp;
            }
            else continue;
        }
        return count;
    }
};