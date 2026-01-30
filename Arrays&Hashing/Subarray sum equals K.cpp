class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int currsum=0;
        int count=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int num:nums){
            currsum+=num;
            if(mp.count(currsum-k)){
                count+=mp[currsum-k];
            }
            mp[currsum]++;
        }
        return count;

    }
};
