class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(!st.empty() && (st.top()+1==s[i] || st.top()+2==s[i])){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};