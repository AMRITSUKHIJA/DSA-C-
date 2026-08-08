class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // last[j] = position in word1 that can be used
        // for word2[j] when matching from the right.
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        // Match word2 from right to left.
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        // Now greedily build the lexicographically smallest answer.
        bool usedMismatch = false;
        j = 0;

        for (i = 0; i < n && j < m; i++) {

            // Exact match: always the best choice.
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }

            // Use our one allowed mismatch.
            else if (!usedMismatch &&
                     (j == m - 1 || i < last[j + 1])) {

                ans[j] = i;
                j++;
                usedMismatch = true;
            }
        }

        // Couldn't construct a sequence of length m.
        if (j != m) {
            return {};
        }

        return ans;
    }
};
