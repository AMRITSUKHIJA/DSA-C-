class Solution {
public:
    int numberOfSubstrings(string s) {
        int n= s.size();
        int l=0;
        int cnt=0;
        vector<int> hash(3,0);
        for(int r=0; r<n; r++){
            hash[s[r]-'a']++;
            while(hash[0]>0 && hash[1]>0 && hash[2]>0){
                cnt+= (n-r);
                hash[s[l]-'a']--;
                l++;
            }
            
       }
       return cnt;
    }
};