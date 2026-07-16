class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref;
        pref.reserve(n);
        int mx = 0;
        for (int x : nums) {
            mx = max(mx, x);
            pref.push_back(std::gcd(x, mx));
        }
        sort(pref.begin(), pref.end());
        long long ans = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            ans += std::gcd(pref[i], pref[j]);
            ++i;
            --j;
        }
        return ans;
    }
};