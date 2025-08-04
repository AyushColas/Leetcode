class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> basket;
        int start = 0, maxCount = INT_MIN;

        for(int end =0; end<fruits.size(); end++){
            basket[fruits[end]]++;

            while(basket.size() > 2){
                basket[fruits[start]]--;
                if(basket[fruits[start]] == 0) basket.erase(fruits[start]); 
                start++;
            }

            maxCount = max(maxCount, end-start+1);
        }

        return maxCount;
    }
};