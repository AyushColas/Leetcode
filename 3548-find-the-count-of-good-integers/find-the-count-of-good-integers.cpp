class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        int m = (n + 1) / 2;
        long long start = 1;
        for (int i = 0; i < m - 1; ++i) {
            start *= 10;
        }
        long long end = start * 10 - 1;
        unordered_set<string> unique_keys;
        
        for (long long i = start; i <= end; ++i) {
            string first_half = to_string(i);
            string reversed = first_half;
            reverse(reversed.begin(), reversed.end());
            string palindrome;
            if (n % 2 == 1) {
                palindrome = first_half + reversed.substr(1);
            } else {
                palindrome = first_half + reversed;
            }
            if (palindrome.size() != n) continue;
            long long num = stoll(palindrome);
            if (num % k != 0) continue;
            string key = palindrome;
            sort(key.begin(), key.end());
            unique_keys.insert(key);
        }
        
        long long result = 0;
        for (const auto& key : unique_keys) {
            vector<int> count(10, 0);
            for (char c : key) {
                count[c - '0']++;
            }
            int count_0 = count[0];
            long long denominator = 1;
            for (int d : count) {
                if (d == 0) continue;
                denominator *= factorial(d);
            }
            long long numerator = (n - count_0) * factorial(n - 1);
            long long permutations = numerator / denominator;
            result += permutations;
        }
        
        return result;
    }
    
private:
    long long factorial(int x) {
        if (x <= 1) return 1;
        long long res = 1;
        for (int i = 2; i <= x; ++i) {
            res *= i;
        }
        return res;
    }
};