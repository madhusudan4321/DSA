class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        vector<string>vec;
        for(int i=0;i+10<=s.size();i++){
            mp[s.substr(i,10)]++;
        }
        for(auto it:mp){
            if(it.second>1){
                vec.push_back(it.first);
            }
        }
        return vec;
    }
};