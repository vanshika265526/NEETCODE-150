/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
  */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> last;
        for(int i=0;i<nums.size();i++){
            //if number seen before
            if(last.count(nums[i])){
                //check dist
                if(i-last[nums[i]]<=k){
                    return true;
                }
            }
            last[nums[i]]=i;
        }
        return false;
    }
};


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i!=j && nums[i]==nums[j] && (abs(i-j)<=k)){
                    return true;
                }
            }

        }
        return false;
    }
};
