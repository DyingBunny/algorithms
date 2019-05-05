/*
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，
 * 使得 num1 成为一个有序数组。
 * */

/*
 * 与合并两个有序链表类似
 * */
#include <vector>
using std::vector;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m - 1, index2 = n - 1;
        int indexMerge = m + n - 1;
        while (index1 >= 0 || index2 >= 0) {
            if (index1 < 0) {
                nums1[indexMerge] = nums2[index2];
                indexMerge--;
                index2--;
            } else if (index2 < 0) {
                nums1[indexMerge] = nums1[index1];
                indexMerge--;
                index1--;
            } else if (nums1[index1] > nums2[index2]) {
                nums1[indexMerge] = nums1[index1];
                indexMerge--;
                index1--;
            } else {
                nums1[indexMerge] = nums2[index2];
                indexMerge--;
                index2--;
            }
        }
    }
};
/*
 * 执行用时 : 16 ms, 在Merge Sorted Array的C++提交中击败了45.84% 的用户
 * 内存消耗 : 8.7 MB, 在Merge Sorted Array的C++提交中击败了81.69% 的用户
 * */
