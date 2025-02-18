class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res=0;
        int Psum=0;
        for(int i=0; i< gain.size(); i++)
        {
            Psum+=gain[i];
            if(Psum > res) res = Psum;
        }

        return res;
    }
};