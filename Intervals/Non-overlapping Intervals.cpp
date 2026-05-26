class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>&b){return a[1]<b[1];});
        int prevend=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(prevend>intervals[i][0]){
                count++;
            }
            else{
                prevend=intervals[i][1];
            }
        }
        return count;
    }
};
