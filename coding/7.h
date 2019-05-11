/*
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转
 * */

#include <limits.h>
class SolutionOne {
public:
    int reverseInt(int x) {
        long long res = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            res = res * 10 + pop;
            if (res > INT_MAX || res < INT_MIN) {
                return 0;
            }
        }
        return res;
    }
};

/*
 * 执行用时 : 12 ms, 在Reverse Integer的C++提交中击败了98.23% 的用户
 * 内存消耗 : 8.3 MB, 在Reverse Integer的C++提交中击败了76.63% 的用户
 * */
