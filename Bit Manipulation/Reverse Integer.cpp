class Solution {
public:
    int reverse(int n) {
    int ans = 0;

    while(n != 0){
        int last = n % 10;

        // overflow check
        if(ans > INT_MAX/10 || ans < INT_MIN/10)
            return 0;

        ans = ans * 10 + last;
        n = n / 10;
    }

    return ans;
}
};
