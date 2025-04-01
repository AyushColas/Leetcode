class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
    make_heap(piles.begin(),piles.end());

    while(k--)
    {
        int maxElement = piles.front();
        maxElement-=floor(maxElement/2);

        pop_heap(piles.begin(),piles.end());
        piles.pop_back();

        piles.push_back(maxElement);
        push_heap(piles.begin(),piles.end());
    }

    int sum=0;
    for(int i:piles)
    {
        sum+=i;
    }

    return sum;
    }
};