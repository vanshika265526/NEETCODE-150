class Solution {
public:
    int solve(vector<int>& arr){
        int n=arr.size();
        if(n==1) return arr[0];
      
         vector<int> dp(n);
         dp[0]=arr[0];
         dp[1]=max(arr[0],arr[1]);
      
         for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],arr[i]+dp[i-2]);

         }
         return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
      
        vector<int> first;
        vector<int> second;
      
        for(int i=0;i<n-1;i++){
            first.push_back(nums[i]);
        }
        for(int i=1;i<n;i++){
            second.push_back(nums[i]);
        }
        return max(solve(first),solve(second));
        
    }
};
