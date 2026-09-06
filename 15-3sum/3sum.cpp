class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                i++;
            }
            int left = i+1;
            int right= nums.size()-1;

            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum==0){
                    st.insert({nums[i],nums[left],nums[right]});
                    if(nums[left]==nums[left+1]){
                        left++;
                    }else if(nums[right]==nums[right-1]){
                        right--;
                    }
                }else if(sum<0){
                    left++;
                }else if(sum>0){
                    right--;
                }
                if(sum==0){
                    left++;
                    right--;
                }
            }

        }
        for(auto e: st){
            ans.push_back(e);
        }
        return ans;
    }
};