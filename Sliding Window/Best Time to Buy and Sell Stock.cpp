class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX;
        int maxbuy=0;
        for(int num:prices){
            minprice=min(minprice,num);
            maxbuy=max(maxbuy,num-minprice);
        }
        return maxbuy;
    }
};
