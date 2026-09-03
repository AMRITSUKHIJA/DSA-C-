class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        // Find the smallest odd number
        for (int x : nums1) {
            if (x % 2 == 1) {
                minOdd = min(minOdd, x);
            }
        }
        // If there are no odd numbers,
        // everything is already even.
        if (minOdd == INT_MAX) {
            return true;
        }
        // Any even number smaller than the smallest odd
        // cannot be converted to odd.
        for (int x : nums1) {
            if (x % 2 == 0 && x < minOdd) {
                return false;
            }
        }
        return true;
    }
};
