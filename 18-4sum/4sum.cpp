class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>>st;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int left = j+1;
                int right = n-1;

                while(left<right){
                    long long sum = 1LL*nums[i]+nums[j]+nums[left]+nums[right];
                    
                    if(sum==target){
                        st.insert({nums[i],nums[j],nums[left],nums[right]});
                        if(left<n && nums[left]==nums[left+1]){
                            left++;
                        }
                        if(right>0 && nums[right]==nums[right-1]){
                            right--;
                        }
                    }else if(sum<target){
                        left++;
                    }else{
                        right--;
                    }
                    if(sum==target){
                        left++;
                        right--;
                    }
                }
            }
        }
        for(auto e:st){
            ans.push_back(e);
        }
        return ans;
    }
};