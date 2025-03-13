class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedList(nums1.size()+nums2.size());

        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),mergedList.begin());

        double mid =0;

        double beg= *mergedList.begin();
        double end= *(mergedList.end()-1);
        int n=mergedList.size();

        if(n % 2 != 0)  return mid= mergedList[n/2];

        if(n % 2 == 0)
        {
            double mid1= mergedList[n/2];
            double mid2= mergedList[n/2-1];
            return mid=(mid1+mid2)/2;
        }

       return mid;
    }
};