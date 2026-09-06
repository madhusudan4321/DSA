class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int max1 = INT_MIN;
        int left = 0;
        if(s.size()==0) return 0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
                count++;
            }else{
                left = max(left,mp[s[i]]);
                mp[s[i]]=i;
                count = i-left;
            }
            max1 = max(max1,count);
        }
        return max1;
    }
};