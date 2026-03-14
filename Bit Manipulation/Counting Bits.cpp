class Solution {
public:
    int count(int number){
        int counts=0;
        while(number){
            counts+=number&1;
            number>>=1;

        }
        return counts;
    }
    vector<int> countBits(int n) {
        vector<int> result;
       for(int i = 0; i <= n; i++){
            result.push_back(count(i));
        }

        return result;

        
    }
};
