class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxE = *max_element(nums.begin(),nums.end());
        int minE = *min_element(nums.begin(),nums.end());
        return gcd(maxE,minE);
    }
};