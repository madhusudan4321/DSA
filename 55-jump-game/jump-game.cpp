class Solution {
public:
//Leetcode
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[0]==0) return false;
            int num = nums[i];
            int j = i;
            if(num==0) return false;
            while(num--){
                j++;
                if(nums[j]>=num){
                    num = nums[j];
                }
                if(j>=nums.size()-1) return true;
            }
        }
        return false;
    }
};


// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         if(nums.size()==1){
//             return true;
//         }
//         for(int i=0;i<nums.size()-1;i++){
//             int num = nums[i];
//             int j = i;
//             if(num>=nums.size()) return true;
//             if(num==0) return false;
//             while(num>0 && num){
//                 num--;
//                 j++;
//                 if(nums[j]>nums[i]){
//                     num = nums[j];
//                 }
//                 if(num==0){
//                     num = nums[j];
//                 }
//                 if(j>=nums.size()-1){
//                     return true;
//                 }
//             }
            
//         }
//         return false;
//     }
// };