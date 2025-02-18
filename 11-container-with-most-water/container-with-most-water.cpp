class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int greatestArea= 0;
        int temp=0;
        while(i<j)
        {
            if(height[i] < height[j])
            {
                temp = height[i]*(j-i);
                if(temp> greatestArea) greatestArea = temp;
                i++;
            }

            else
            {
                temp = height[j]*(j-i);
                if(temp> greatestArea) greatestArea = temp;
                j--;
            }
        }
        return greatestArea;
    }
};