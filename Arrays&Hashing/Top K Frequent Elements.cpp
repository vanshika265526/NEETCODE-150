/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:
Input: nums = [1], k = 1
Output: [1]
*/class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }

        vector<vector<int>> bucket(nums.size()+1);
        for(auto it:count){
            bucket[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i=bucket.size()-1;i>=0 && ans.size()<k;i--){
            for(int num:bucket[i]){
                ans.push_back(num);
                if(ans.size()==k) break;
            }
        }
        return ans;
    }
};
