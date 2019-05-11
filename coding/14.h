/*
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 *
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 * 示例 1:
 *
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * */

#include <iostream>
#include <string>
#include <vector>
using std::min;
using std::vector;
using std::string;

class Solution {
public:
    string longestCommonPrefix(vector<string>& nums) {
        if (nums.empty()) {
            return "";
        }
        return longestCommonPrefix(nums, 0, nums.size() - 1);
    }
    string longestCommonPrefix(vector<string>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        } else {
            int mid = (left + right) / 2;
            string lcpleft = longestCommonPrefix(nums, left, mid);
            string lcpright = longestCommonPrefix(nums, mid + 1, right);
            return commonPrefix(lcpleft, lcpright);
        }
    }
    string commonPrefix(string& left, string& right) {
        int _min = min(left.size(), right.size());
        for (int i = 0; i < _min; i++) {
            if (left[i] != right[i]) {
                return left.substr(0, i);
            }
        }
        return left.substr(0, _min);
    }
};
