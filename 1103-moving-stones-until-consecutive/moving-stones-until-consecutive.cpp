class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> stone= {a,b,c};
        vector<int> res(2,0);

        sort(stone.begin(),stone.end());

        res[1] = stone[2] - stone[0] - 2;

        int leftGap = stone[1] - stone[0];
        int rightGap = stone[2] - stone[1];

        if (leftGap == 1 && rightGap == 1) res[0] = 0;
        else if (leftGap <= 2 || rightGap <= 2) res[0] = 1;
        else res[0] = 2;

        return res;
    }
};