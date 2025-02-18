class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<long long> res(size, 1);

    long long prefix = 1;
    for (int i = 0; i < size; i++) {
        res[i] = prefix;
        prefix *= nums[i];
    }

    long long suffix = 1;
    for (int i = size - 1; i >= 0; i--) {
        res[i] *= suffix;
        suffix *= nums[i];
    }

    vector<int> result(size);
    for (int i = 0; i < size; i++) {
        result[i] = static_cast<int>(res[i]);
    }

    return result;
}
};