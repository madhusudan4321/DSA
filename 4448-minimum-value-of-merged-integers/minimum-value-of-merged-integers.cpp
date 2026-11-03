class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i=0;i<nums.size()-1;i+=2){
            string n = "";
            n += to_string(nums[i]);
            n+= to_string(nums[i+1]);

            mini = min(mini,stoi(n));
        }
        return mini;
    }
};