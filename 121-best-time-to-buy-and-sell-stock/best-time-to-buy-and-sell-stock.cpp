class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max1 = INT_MIN;
        int best=INT_MAX;
        for(int i=0;i<prices.size();i++){
            best = min(best,prices[i]);
            max1 = max(max1,prices[i]-best);
        }
        return max1;
    }
};