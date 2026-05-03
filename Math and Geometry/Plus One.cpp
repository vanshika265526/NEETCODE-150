class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // traverse from last digit
        for (int i = n - 1; i >= 0; i--) {

            // if digit is less than 9 → just add 1 and return
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // if digit is 9 → make it 0 (carry forward)
            digits[i] = 0;
        }

        // if all digits were 9 (like 999 → 1000)
        digits.insert(digits.begin(), 1);

        return digits;
    }
};
