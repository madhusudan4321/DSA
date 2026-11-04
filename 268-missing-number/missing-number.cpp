class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        sort(nums.begin(),nums.end());
        while(left<=right){
            int mid = left+(right-left)/2;
            if(mid==nums[mid]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return left;
    }
};