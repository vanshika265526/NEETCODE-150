class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        for(int num : nums)
            xor_all ^= num;
        
        int mask = xor_all & -xor_all;  // rightmost set bit
        
        int a = 0, b = 0;
        for(int num : nums){
            if(num & mask)
                a ^= num;    // group 1
            else
                b ^= num;    // group 2
        }
        
        return {a, b};
    }
};
