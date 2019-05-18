/*
 * 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增
 * 的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样
 * 的一个二维数组和一个整数，判断数组中是否含有该整数。
 * */

#include <vector>
using std::vector;

class SolutionOne {
public:
    bool Find(int target, vector<vector<int> > array) {
        int size = array.size();
        for (int i = 0; i < size; i++) {
            int low = 0, high = array[i].size() - 1;
            while (low <= high) {
                int middle = (low + high) / 2;
                if (target == array[i][middle])
                    return true;
                else if (target > array[i][middle])
                    low = middle + 1;
                else
                    high = middle - 1;
            }
        }
        return false;        
    }
};

/*
 * 时间复杂度 nlogn
 * */
