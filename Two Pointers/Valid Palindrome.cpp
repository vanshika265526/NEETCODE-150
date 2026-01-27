/*
Given a string s, return true if it is a palindrome, otherwise return false.
A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.
Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        while(left < right){
          //skipping non alphanumeric leftside
            while(left< right && !isalnum(s[left]))left++;
          //skipping non alphanumeric rightside
            while(left<right && !isalnum(s[right]))right--;
          //checking with conversion in lowercase
            if(tolower(s[left])!=tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};
