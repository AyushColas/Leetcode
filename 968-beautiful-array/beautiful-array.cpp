class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> result = {1};
        while (result.size() < N) {
            vector<int> temp;
            for (int num : result) {
                if (num * 2 - 1 <= N) temp.push_back(num * 2 - 1);
            }
            for (int num : result) {
                if (num * 2 <= N) temp.push_back(num * 2);
            }
            result = temp;
        }
        return result;
    }
};