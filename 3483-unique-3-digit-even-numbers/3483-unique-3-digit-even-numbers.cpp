class Solution {
public:
    int totalNumbers(vector<int>& digit) {
        unordered_set<int> st;
        int n = digit.size();
        for(int i = 0;i <n;i++){
            for(int j = 0;j<n;j++){
                for(int k = 0;k<n;k++){
                    if(i==j||j==k||k==i) continue; // to take different index
                    int a = digit[i];
                    int b = digit[j];
                    int c = digit[k];
                    if(a==0) continue; // the leading number is not equal to zero
                    if(c%2 !=0) continue; // last number is always even;
                    int number = a*100+b*10 + c;
                    st.insert(number);

                }
            }
        }
        return st.size();
    }
};