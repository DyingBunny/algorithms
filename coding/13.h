/*
 * 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
 *
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * */

/*
 * 所有组合
 * I    1
 * IV   4
 * IX   9
 * X    10
 * XL   40
 * XC   90
 * C    100
 * CD   400
 * CM   900
 * V    5
 * D    500
 * M    1000
 * L    50
 * 共 13 中组合
 * */

#include <string>
#include <iostream>
using std::string;

class SolutionOne {
public:
    int romanToInt(string s) {
        int result = 0;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            switch(s[i])
            {
            case 'I':
                if (i < size - i && s[i + 1] == 'V') {
                    result += 4;
                    i++;
                } else if (i < size - 1 && s[i + 1] == 'X') {
                    result += 9;
                    i++;
                } else {
                    result++;
                }
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                if (i < size - 1 && s[i + 1] == 'L') {
                    result += 40;
                    i++;
                } else if (i < size - 1 && s[i + 1] == 'C') {
                    result += 90;
                    i++;
                } else {
                    result += 10;
                }
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                if (i < size - 1 && s[i + 1] == 'D') {
                    result += 400;
                    i++;
                } else if (i < size - 1 && s[i + 1] == 'M') {
                    result += 900;
                    i++;
                } else {
                    result += 100;
                }
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
            }
        }
        return result;
    }
};

/*
 * 执行用时 : 28 ms, 在Roman to Integer的C++提交中击败了99.70% 的用户
 * 内存消耗 : 8.5 MB, 在Roman to Integer的C++提交中击败了86.49% 的用户
 * */
