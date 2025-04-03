class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int> &a,vector<int> &b)
        {
            return a[1]>b[1];
        });

        int maxSum = 0;

        for(auto i: boxTypes)
        {
            int count=min(truckSize, i[0]);
            maxSum += count*i[1];
            truckSize-=count;

            if(truckSize==0) break;
        }

        return maxSum;
    }
};