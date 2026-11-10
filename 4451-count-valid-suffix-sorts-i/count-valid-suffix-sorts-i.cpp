class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<bool>prefix(n,true);
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]&&(nums[i-1]==target[i-1]);
        }

        unordered_map<int,int>freq;
        int nonZero = 0;

        auto update = [&](int x,int val){
            int oldval = freq[x];
            int newval = oldval+val;

            if(oldval==0 && newval!=0){
                nonZero++;
            }else if(oldval!=0 && newval==0){
                nonZero--;
            }

            freq[x] = newval;
        };

        int ans = 0;
        bool sorted = true;
        for(int i=n-1;i>=0;i--){
            update(nums[i],1);
            update(target[i],-1);

            if(i<n-1 && target[i]<target[i+1]){
                sorted=false;
            }

            if(prefix[i] && sorted && nonZero==0){
                ans++;
            }
        }
        return ans;
    }
};