class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        // Sum of the subarray we want to KEEP
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long target = total - x;

        // If target < 0, even removing everything isn't enough.
        if (target < 0) return -1;

        // target == 0 means we remove the entire array.
        if (target == 0) return n;

        int left = 0;
        long long sum = 0;
        int maxLen = -1;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            // Shrink window until sum <= target
            while (sum > target && left <= right) {
                sum -= nums[left];
                left++;
            }

            // Found a subarray with sum == target
            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        // No valid subarray
        if (maxLen == -1) return -1;

        return n - maxLen;
    }
};
