class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        for(int num : nums)
            xor_all ^= num;
        
        // safe negation
        unsigned int mask = xor_all & (unsigned int)(-(long long)xor_all);
        
        int a = 0, b = 0;
        for(int num : nums){
            if(num & mask)
                a ^= num;
            else
                b ^= num;
        }
        
        return {a, b};
    }
};
