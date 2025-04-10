class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        auto count = [&](long long x) -> long long {
            if (x < 1) return 0;
            long long s_num = stoll(s);
            int len_s = s.size();
            string x_str = to_string(x);
            int len_x = x_str.size();
            
            if (len_s > len_x) return 0;
            if (s_num > x) return 0;
            
            long long sum_l_less = 0;
            int max_l_less = len_x - 1;
            int min_l = len_s;
            
            if (min_l <= max_l_less) {
                for (int l = min_l; l <= max_l_less; ++l) {
                    int m = l - len_s;
                    if (m == 0) {
                        sum_l_less += 1;
                    } else {
                        long long ways = limit;
                        for (int i = 0; i < m - 1; ++i) {
                            ways *= (limit + 1);
                        }
                        sum_l_less += ways;
                    }
                }
            }
            
            int len_p = len_x - len_s;
            if (len_p < 0) return sum_l_less;
            
            string x_p_str = (len_p > 0) ? x_str.substr(0, len_p) : "";
            string x_s_str = (len_p > 0) ? x_str.substr(len_p) : x_str;
            long long x_s_num = stoll(x_s_str);
            
            if (len_p == 0) {
                return sum_l_less + 1;
            }
            
            vector<int> x_p_digits;
            for (char c : x_p_str) {
                x_p_digits.push_back(c - '0');
            }
            
            int n = len_p;
            vector<vector<long long>> memo(n, vector<long long>(2, -1));
            
            function<long long(int, bool)> dp = [&](int pos, bool tight) -> long long {
                if (pos == n) {
                    return (tight ? (s_num <= x_s_num ? 1 : 0) : 1);
                }
                if (memo[pos][tight] != -1) {
                    return memo[pos][tight];
                }
                long long res = 0;
                int max_d = limit;
                if (tight) {
                    max_d = min(max_d, x_p_digits[pos]);
                }
                int start_d = (pos == 0) ? 1 : 0;
                if (start_d > max_d) {
                    return memo[pos][tight] = 0;
                }
                for (int d = start_d; d <= max_d; ++d) {
                    bool new_tight = tight && (d == x_p_digits[pos]);
                    res += dp(pos + 1, new_tight);
                }
                return memo[pos][tight] = res;
            };
            
            long long count_l_equal = dp(0, true);
            return sum_l_less + count_l_equal;
        };
        
        long long upper = count(finish);
        long long lower = (start > 1) ? count(start - 1) : 0;
        return upper - lower;
    }
};