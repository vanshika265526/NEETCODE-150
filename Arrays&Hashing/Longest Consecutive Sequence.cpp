/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
  */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int longest=0;    //keeps track of current longest found
        for(int num:st){
            if(st.find(num-1)==st.end()){         //means as long as num-1 doesnt exist=>finding start position
                int curr=num;
                int count=1;
                while(st.find(curr+1)!=st.end()){        //means as long as curr+1 exits=>consecutive
                    count++;
                    curr++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};
