class Solution {
public:
    int solve(vector<int>& nums, int i, int j) {
        // Only one element left
        if (i == j)
            return nums[i];

        // Maximum score difference current player can achieve
        int pickLeft = nums[i] - solve(nums, i + 1, j);
        int pickRight = nums[j] - solve(nums, i, j - 1);

        return max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};