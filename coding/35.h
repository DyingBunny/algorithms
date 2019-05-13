/*
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
 * 如果目标值不存在于数组中，返回它将会被按顺序插入的位置
 * 
 * 这是一道典型的二分查找题目，题目场景有以下特点：
 *
 * 数组是有序的
 * 答案是有界的
 * 目标值越大，答案越大，这里有一个单调递增的关系
 * */

#include <vector>
using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int middle = (left + right) / 2;
            if (nums[middle] == target) {
                return middle;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }
        return left;
    }
};

/*
 * 执行用时 : 16 ms, 在Search Insert Position的C++提交中击败了41.92% 的用户
 * 内存消耗 : 9 MB, 在Search Insert Position的C++提交中击败了70.06% 的用户
 * */
