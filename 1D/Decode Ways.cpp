class Solution {
public:
    int solve(int i, string &s, vector<int>& dp) {
        // reached end -> one valid decoding
        if(i == s.length()) return 1;
        // strings starting with 0 invalid
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        // take single digit
        int ans = solve(i + 1, s, dp);
        // take two digits
        if(i + 1 < s.length()) {
            int num = (s[i] - '0') * 10 + (s[i+1] - '0');
            if(num >= 10 && num <= 26) {
                ans += solve(i + 2, s, dp);
            }
        }
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(0, s, dp);
    }
};
