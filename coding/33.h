/*
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 *
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2]  )。
 *
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 *
 * 你可以假设数组中不存在重复的元素。
 *
 * 你的算法时间复杂度必须是 O(log n) 级别
 * 
 * 示例 1:
 *
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 分析题目可知：
 *
 * 数组旋转之前是有序的
 *
 * 答案是有界的
 *
 * 目标值越大，答案越大，这里有一个单调递增的关系
 * */

/*
 * 思路：
 * 与标准的二分查找题目相比，只多了一个条件，有序数组被旋转了，只要先将数组旋转回来，再用二分查找求出结果即可
 *
 * 其实很多中等题目都是在典型的算法题上拐一个弯，困难题一般是柔和两种算法
 * 其实本质不变，有一句话说得好，万变不离其宗，宗是课文的知识点
 * */

#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    /*
     * 搜索旋转排序数组
     * */
    int search(vector<int>& nums, int target) {
        
        /*
         * 在这里旋转排序数组已经编程排序数组
         * 接下来就是我们最熟悉的二分查找
         * */
        return binarySearch(nums, target);
    }
    
    /*
     * 获取旋转数组的下标
     * 
     * 这里还可以用找此时数组的最小元素，进而找到旋转数组的下标
     * 进而获得旋转前的的数组
     * */
    int getRotateIndex(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] > nums[i + 1]) {
                return i + 1;
            }
        }
        return 0;
    }

    /*
     * 获取旋转前的排序数组
     * */
    vector<int> getRotateArray(vector<int>& nums, int index);

    int binarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int middle = (left + right) / 2;
            if (nums[middle] == target) {
                return middle;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return 0;
    }
};

/*
 * 思路一：
 * 整体思路：先用二分法找出最小值，也是那个分割点,例如 [4,5,6,7,0,1,2]，我们找出数字 0；
 *
 * 接下来判断 target 是在分割点的左边还是右边;
 *
 * 最后再使用一次二分法找出 target 的位置. 所以时间复杂度为：O(logn)O(logn)
 *
 * 只有一个难点，那就是如何通过二分法找出那个分割点呢？
 *
 * 就是和它的右端点比较判断，直接看代码吧！
 * */

/*
 * 思路二：
 * 直接使用二分法，判断那个二分点,有几种可能性
 *
 * 直接等于target
 *
 * 在左半边的递增区域
 *
 * a. target 在 left 和 mid 之间
 *
 * b. 不在之间
 *
 * 在右半边的递增区域
 *
 * a. target 在 mid 和 right 之间
 *
 * b. 不在之间
 * */

/*
 * 解题思路：
 * 此题主要强制使用log(n)的时间复杂度，能够达到的就是二分法，实现类似的是归并排序中的二分法。 
 * 也就是将数组不断的进行二分，然后在各个区域中找，如果区域中没有则返回-1，
 * 然后对返回的索引进行最大值比较，如果都为-1 则就没有，如果某个区域有，
 * 则就返回区域中的最大值（其他的都是-1，因为没有重复的） 
 * */
