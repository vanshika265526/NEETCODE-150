class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {

            int tempmax = max({nums[i], nums[i] * mini, nums[i] * maxi});
            int tempmin = min({nums[i], nums[i] * mini, nums[i] * maxi});
            maxi = tempmax;
            mini = tempmin;
            ans = max(maxi, ans);
        }
        return ans;
    }
};
