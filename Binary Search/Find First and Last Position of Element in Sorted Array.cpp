class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstElement(nums, target);
        int second=secondElement(nums, target);
        return {first,second};
    }

        int firstElement(vector<int>& nums, int target){
            int low=0;
            int high=nums.size()-1;
            int ans=-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(nums[mid]==target){
                    ans=mid;
                    high=mid-1;
                }
                else if(nums[mid]<target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            return ans;
        }
        int secondElement(vector<int>& nums,int target){
            int low=0;
            int high=nums.size()-1;
            int ans=-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(nums[mid]==target){
                    ans=mid;
                    low=mid+1;
                }
                else if(nums[mid]>target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }

            }
            return ans;
        }

};
