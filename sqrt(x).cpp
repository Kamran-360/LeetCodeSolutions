//solution of square root of x without inbuilt functions i.e pow(x,0.5) in c++
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;

        int left = 0;
        int right = INT_MAX;

        while (true) {
            int mid = left + (right - left) / 2; //subtracting left from right to avoid overflow fo integer (b'coz when we add positive integer we always gonna get larger number) 
            // if integer is negative return it back (square root of a negative number is considered undefined)
            if (mid == 0) {
                cout << mid<<endl;
                return x;  
            }

            if (mid > x / mid) {
                right = mid - 1;
            } else {
                int nextMid = mid + 1;
                if (nextMid > x / nextMid) {
                    return mid;
                }
                left = mid + 1;
            }
        }
    }
};
// problem : https://leetcode.com/problems/sqrtx/description/
/*Here using binary search with the intuition is that we have to 
divide the target number with the mid till we find such number when target number
divisible by that (mid +1) the result is less than (mid + 1) then that mid is the 
final answer.
i.e in case of 8 its 3
*/
