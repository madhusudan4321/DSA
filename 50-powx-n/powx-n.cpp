class Solution {
public:
    double myPow(double x, int n) {

        long long N = n;                    // CHANGED

        if(N < 0){                          // CHANGED
            x = 1 / x;                      // CHANGED
            N = -N;                         // CHANGED
        }

        if(N == 0) return 1;

        double halfpow = myPow(x, N / 2);   // CHANGED
        double halfpowsq = halfpow * halfpow;

        if(N % 2 != 0){                     // CHANGED
            return x * halfpowsq;
        }

        return halfpowsq;
    }
};