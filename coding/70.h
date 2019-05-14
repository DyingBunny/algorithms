/*
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 *
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 * 注意：给定 n 是一个正整数。
 * */

/*
 * 假设 n 为台阶数
 *
 * if   n = 1; func1 = 1;
 * if   n = 2; func2 = 2;
 * else
 *      res = func1 + func2
 *      func1 = func2
 *      func2 = res
 *      此种方法可以用数学公式推导，相信有一定数学功底的
 *      动态规划问题，可以用数学知识进行解答，这可能相对来水比较难推导
 * */

class Solution {
public:
    int climbStairs(int n) {
        int first = 1;
        int second = 1;
        int result = 0;
        for (int i = 2; i <= n; i++) {
            result = first + second;
            first = second;
            second = result;
        }
        return result;
    }
};

/*
 * 执行用时 : 0 ms, 在Climbing Stairs的C++提交中击败了100.00% 的用户
 * 内存消耗 : 8.3 MB, 在Climbing Stairs的C++提交中击败了60.65% 的用户
 * */
