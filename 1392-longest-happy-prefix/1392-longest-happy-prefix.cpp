class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int>LPS(n,0);
        LPS[0] = 0;
        int i = 1;
        int len = 0;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                LPS[i] = len;
                i++;
            }else{
                if(len!=0){
                    len = LPS[len-1];
                }else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
        return s.substr(0,LPS[n-1]);
    }
};