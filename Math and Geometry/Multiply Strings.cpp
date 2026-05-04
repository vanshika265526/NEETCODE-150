class Solution {
public:
    string multiply(string num1, string num2) {
        int m=num1.size();
        int n=num2.size();
        //ans should be less than m+n
        vector<int> result(m+n,0);

        //start from back of the numbers as we do in multiplication on pages
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int sum=mul+result[i+j+1];
                
                result[i+j+1]=sum%10;
                result[i+j]+=sum/10;
            }
        }

        //convert to string
        string ans="";
        for(int num:result){
            if(!(ans.empty()&& num==0)){
                ans.push_back(num+'0');
            }
        }
        return ans.empty()?"0":ans;
        
    }
};
