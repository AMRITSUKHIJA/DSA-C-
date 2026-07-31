class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c : word)
            freq[c - 'a']++;
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;
            int cost = i / 8 + 1;   // First 8 ->1, next 8 ->2, next 8 ->3, last 2 ->4
            ans += freq[i] * cost;
        }
        return ans;
    }
};