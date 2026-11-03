class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i=1;i<nums.size();i+=2){
            int n = log10(nums[i])+1;
            int first = nums[i-1];
            int num = first*pow(10,n);
            mini = min(mini,num+nums[i]);
        }
        return mini;
    }
};