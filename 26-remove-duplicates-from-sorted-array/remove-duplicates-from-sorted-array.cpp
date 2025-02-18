class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        auto it= nums.begin();

        while(it != nums.end()-1){
            if(*it == *(it+1)) it =nums.erase(it);
        else{
            it++;
        }
    }

     return nums.size();
    }
};