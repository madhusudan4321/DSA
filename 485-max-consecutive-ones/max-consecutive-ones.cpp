class Solution {
public:
    //leetcode
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max1 = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            max1 = max(max1,count);
            if(nums[i]==0){
                count = 0;
            }
        }
        return max1;
    }
};