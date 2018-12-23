// C/C++ File
// AUTHOR:   jetchars
// FILE:     0371_sum_of_2_int/sum_of_2_int.cc
// ROLE:     TODO (some explanation)
// CREATED:  2017-07-25 00:11:26
// MODIFIED: 2017-07-25 00:23:16

/* Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -. */

/* Example: */
/* Given a = 1 and b = 2, return 3. */

/* Credits: */
/* Special thanks to @fujiaozhu for adding this problem and creating all test cases. */

class Solution {
public:
    int getSum(int a, int b) {
        int x, y=1;
        while(y){
            x = a^b;
            y = a&b;
            y <<= 1;
            a = x;
            b = y;
        }
        return x;
    }
};
