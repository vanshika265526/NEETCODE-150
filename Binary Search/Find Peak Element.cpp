class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If the right neighbor is bigger, go right (ascending slope)
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } 
            // Else, go left (descending slope — peak might be here or left)
            else {
                right = mid;
            }
        }

        // left == right --> peak found
        return left;
    }
};
