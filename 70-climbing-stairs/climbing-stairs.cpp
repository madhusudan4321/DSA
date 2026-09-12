class Solution {
public:
    int DP(int n,vector<int>&vec){
        if(n==0 || n==1) return 1;
        if(vec[n]!=-1){
            return vec[n];
        }
        vec[n]= DP(n-1,vec)+DP(n-2,vec);
        return vec[n];
    }
    int climbStairs(int n) {
        vector<int>vec(n+1,-1);
        int ans = DP(n,vec);
        return ans;

    }
};