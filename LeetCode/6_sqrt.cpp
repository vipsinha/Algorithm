/*

69. Sqrt(x)
Solved
Easy
Topics
Companies
Hint
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1
*/

#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x, mid = -1;

        if ((x == 0) || (x == 1)) {
            return x;
        }

        while (low <= high) {
            long mid = low + (high - low) / 2;
            long long sqr = mid * mid;

            // If the square of mid is greater than x, we know the square root
            // lies in the lower half
            if (sqr > x) {
                high = mid - 1;
            // If the square of mid is equal to x, we have found the square
            // root
            } else if (sqr == x) {
                return mid;
            // If the square of mid is less than x, we know the square root
            // lies in the upper half
            } else {
                low = mid + 1;
            }
        }

        return floor (high);
    }
};

int main(){

    Solution sol;
    //std::cout << sol.isValid("]");
    return 0;
}