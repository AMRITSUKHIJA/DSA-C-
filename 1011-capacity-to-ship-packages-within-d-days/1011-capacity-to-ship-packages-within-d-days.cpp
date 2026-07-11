class Solution {
public:
    bool check(vector<int>& weights, int days,int mid){
        int curr = 0;
        int currDays = 0;
        for(int i=0;i<weights.size();i++){
            curr+=weights[i];
            if(weights[i]>mid) return false;
            if(curr > mid){
                currDays++;
                curr = 0;
            }
            if(curr==0) curr+=weights[i];

        }
        if(currDays < days) return true;

        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int totalSum = accumulate(weights.begin(),weights.end(),0);
        int l = 1;
        int r = totalSum;
        int ans = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(weights,days,mid)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
       cout << check(weights,days,2);
        return ans;
    }
};