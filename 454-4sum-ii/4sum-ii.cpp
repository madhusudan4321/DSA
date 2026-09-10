class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int count = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                mp[nums3[i]+nums4[j]]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum = nums1[i]+nums2[j];
                int remain = 0-sum;
                if(mp.find(remain)!=mp.end()){
                    count+=mp[remain];
                }
            }
        }
        return count;
    }
};