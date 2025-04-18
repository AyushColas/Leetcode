#include <vector>
using namespace std;

class Solution {
private:
    static const int MOD = 1337;
    
    int pow(int a, int b) {
        int res = 1;
        a %= MOD;
        for (int i = 0; i < b; i++) {
            res = (res * a) % MOD;
        }
        return res;
    }

public:
    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int i = b.size() - 1; i >= 0; i--) {
            res = (res * pow(a, b[i])) % MOD;
            a = pow(a, 10);
        }
        return res;
    }
};
