/*
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 * */
#include <string>
using std::string;
class SolutionOne {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return isPalindrome(s, left, right - 1) || isPalindrome(s, left + 1, right);
            }
            left++;
            right--;
        }
        return true;
    }
private:
    bool isPalindrome(string s, int left, int right) {
        if (s.empty()) {
            return true;
        }
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

/*
 * 执行用时 : 156 ms, 在Valid Palindrome II的C++提交中击败了34.44% 的用户
 * 内存消耗 : 26 MB, 在Valid Palindrome II的C++提交中击败了56.65% 的用户
 * */
