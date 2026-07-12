class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>arr2 = arr;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mpp;
        int i = 1;
        for(auto it:arr){
            if(mpp.find(it)==mpp.end()){
                mpp[it]=i++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr2[i] = mpp[arr2[i]];
        }
        return arr2;
    }
};