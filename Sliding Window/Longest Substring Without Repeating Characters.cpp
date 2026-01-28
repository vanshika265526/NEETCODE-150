class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int result=0;
        unordered_set<char> check;
        for(int right=0;right<s.size();right++){
            //if right exists, remove left and move one pointer ahead
            while(check.find(s[right])!=check.end()){
                check.erase(s[left]);
                left++;
            }
            check.insert(s[right]);
            result=max(result,right-left+1);
        }
        return result;
    }
};
