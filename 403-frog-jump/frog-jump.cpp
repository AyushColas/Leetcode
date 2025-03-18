class Solution {
public:
     unordered_map<int, unordered_set<int>> memo;
    unordered_set<int> stoneSet;

    bool dfs(int pos, int jump, int lastStone) {
        if (pos == lastStone) return true;
        if (memo[pos].count(jump)) return false;

        for (int nextJump : {jump - 1, jump, jump + 1}) {
            if (nextJump > 0 && stoneSet.count(pos + nextJump)) {
                if (dfs(pos + nextJump, nextJump, lastStone))
                    return true;
            }
        }

        memo[pos].insert(jump);
        return false;
    }

    bool canCross(vector<int>& stones) {
        stoneSet = unordered_set<int>(stones.begin(), stones.end());
        return dfs(0, 0, stones.back());
    }
};