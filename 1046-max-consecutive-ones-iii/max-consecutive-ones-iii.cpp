class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        int max1 = INT_MIN;
        int left = 0;
        int zerocount = 0;
        if(k>=nums.size()){
            return k;
        }
        for(int right = 0;right<nums.size();right++){
            count++;
            if(nums[right]==0){
                zerocount++;
            }
            if(zerocount>k){
                while(zerocount>k){
                    if(nums[left]==0){
                        zerocount--;
                    }
                    left++;
                    count--;
                }
                
            }
            max1 = max(max1,count);
            
        }
        return max1;
    }
};