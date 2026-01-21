/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false
  */

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false; 
        unordered_map<char,int> freq;
        for(char c:s) freq[c]++;
        for(char c:t){
            if(freq[c]==0) return false;
            freq[c]--;
        }
        return true;
        
    }
};
