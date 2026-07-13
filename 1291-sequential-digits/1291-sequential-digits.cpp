class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string s = "123456789";
        int low_size = to_string(low).length();
        int high_size = to_string(high).length();
        for (int i = low_size; i <= high_size; i++) {
            for (int l = 0; l + i <= 9; l++) {
                int curr = stoi(s.substr(l, i));
                if (curr >= low && curr <= high) {
                    res.push_back(curr);
                }
            }
        }
        return res;
    }
};