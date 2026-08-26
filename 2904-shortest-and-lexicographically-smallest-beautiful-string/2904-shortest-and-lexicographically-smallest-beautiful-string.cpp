class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                ones.push_back(i);
        }

        if (ones.size() < k)
            return "";

        string ans = "";

        for (int i = 0; i + k - 1 < ones.size(); i++) {
            int left = ones[i];
            int right = ones[i + k - 1];

            string cur = s.substr(left, right - left + 1);

            if (ans.empty() || cur.size() < ans.size() ||
                (cur.size() == ans.size() && cur < ans)) {
                ans = cur;
            }
        }

        return ans;
    }
};