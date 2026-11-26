class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        int bob = 10;
        int alice = 10;
        bool ans = false;
        while(n>=0){
            if(n<alice){
                ans = false;
                break;
            }else{
                n-=alice;
                alice--;
                bob = alice;
            }
            if(n<bob){
                ans = true;
                break;
            }else{
                n-=bob;
                bob--;
                alice = bob;
            }
        }
        return ans; 
    }
};