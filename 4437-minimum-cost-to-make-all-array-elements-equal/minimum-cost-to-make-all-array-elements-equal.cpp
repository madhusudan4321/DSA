class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        long long ans =  LLONG_MAX;
        while(i<n){
           int j = i;
            while(j<n && nums[j]==nums[i]){
                j++;
            } 
            int L = i;
            int R = j-1;

            if(L==0 && R==n-1) return 0;
            
            bool ans1 = (L==0 || (L>0 && L<n-1));
            bool ans2 = (R==n-1 || (R>0 && R<n-1));

            if(ans1 && ans2){
                long long cost = 0;
                if(L>0){
                    cost+= (long)L*nums[L];
                }
                if(R<n-1){
                    cost+= (long)(n-1-R)*nums[R];
                }
                ans = min(ans,cost);
            }
            i=j;
        }
        return ans;
    }
};