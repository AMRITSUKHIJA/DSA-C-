class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<int, int> mp1;
        for(int i=0; i<magazine.size(); i++){
            mp1[magazine[i]]++;
        }
        map<int, int> mp2;

        for(int i=0; i<ransomNote.size(); i++){
            mp2[ransomNote[i]]++;
        }
        for(int i=0; i<ransomNote.size(); i++){
            if(mp2[ransomNote[i]]>mp1[ransomNote[i]] ){
                return false;
            }
        }
        return true;
    }
};