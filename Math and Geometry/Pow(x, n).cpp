class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;   // avoid overflow
    double ans = 1;

    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    while (N > 0) {
        if (N % 2 == 1) {   // if odd
            ans = ans * x;
        }

        x = x * x;   // square
        N = N / 2;   // halve
    }

    return ans;
        
    }
};
