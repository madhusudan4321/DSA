class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int count = n;
        int last = nums.size();
        if(n==0) return true;
        for(int i=0;i<last;i++){
            if(nums[i]==0){
                bool left = (i==0 || nums[i-1]==0);
                bool right = (i==last-1 || nums[i+1]==0);

                if(left && right){
                    nums[i]=1;
                    count--;
                if(count==0) return true;
                    }
                }
        }
        return false;
    }
};