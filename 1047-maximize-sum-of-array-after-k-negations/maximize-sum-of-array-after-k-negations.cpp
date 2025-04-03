class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
    
    sort(nums.begin(),nums.end());

    for(int i=0; i<nums.size() && nums[i]<0 && k>0;i++)
    {
        nums[i]=-nums[i];
        k--;
    }

    sort(nums.begin(),nums.end());

    if(k%2==1) nums[0] = -nums[0];

    int ans=0;

    for(int i:nums)
    {   
        ans+=i;
    }

    return ans;
    }
};