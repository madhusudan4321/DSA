class Solution {
public:
    void Combination(vector<int>&nums,vector<int>&vec,vector<vector<int>>&ans,int i,int n,int target){
        if(target==0){
            ans.push_back(vec);
            return;
        }
        if(i==n){
            return;
        }
        if(target<0){
            return;
        }
        vec.push_back(nums[i]);
        Combination(nums,vec,ans,i,n,target-nums[i]);
        vec.pop_back();
        Combination(nums,vec,ans,i+1,n,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>vec;
        vector<vector<int>>ans;

        Combination(nums,vec,ans,0,nums.size(),target);
        return ans;
    }
};