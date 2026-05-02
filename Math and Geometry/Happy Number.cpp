class Solution {
public:
    // function to calculate next number
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);  // fast starts one step ahead

        // loop until fast reaches 1 OR both meet (cycle)
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);              // move 1 step
            fast = getNext(getNext(fast));     // move 2 steps
        }

        return fast == 1;   // if reached 1 → happy
    }
};
