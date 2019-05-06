#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::vector;

const int BUCKETNUM = 10;

template<typename T>
class Sort {
public:

    /*
     * 选择冒泡排序思路：
     * 1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
     * 2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
     * 3. 针对所有的元素重复以上的步骤，除了最后一个。
     * 4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
     * */

    static void bubbleSort(vector<int>& v) {
        int size = v.size();
        bool flag = false;
        for (int i = 0; i < size - 1 && !flag; i++) {
            flag = true;
            for (int j = 0; j < size - i - 1; j++) {
                if (v[j] > v[j + 1]) {
                    flag = false;
                    int tmp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = tmp;
                }
            }
        }
    }

    /*
     * 选择排序思路：
     * 1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
     * 2. 从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
     * 3. 以此类推，直到所有元素均排序完毕
     * */

    static void selectSort(vector<int>& v) {
        int size = v.size();
        int _min;
        for (int i = 0; i < size - 1; i++) {
            _min = i;
            for (int j = i + 1; j < size; j++) {
                if (v[j] < v[_min]) {
                    _min = j;
                }
            }
            if (i != _min) {
                int tmp = v[i];
                v[i] = v[_min];
                v[_min] = tmp;
            }
        }
    }

    /*
     * 归并排序：把数据分为两段，从两段中逐个选最小的元素移入新数据段的末尾。可从上到下或从下到上进行。
     * */

    static void mergeSort(vector<int>& v1, vector<int>& v2, int start, int end) {
        if (start >= end) {
            return;
        }
        int size = end - start;
        int middle = (size >> 1) + start;
        int start1 = start, end1 = middle;
        int start2 = middle + 1, end2 = end;
        mergeSort(v1, v2, start1, end1);
        mergeSort(v1, v2, start2, end2);
        int k = start;
        while (start1 <= end1 && start2 <= end2) {
            v2[k] = v1[start1] < v1[start2] ? v1[start1] : v1[start2];
            k++;
            start1++;
            start2++;
        }
        while (start1 <= end1) {
            v2[k] = v1[start1];
            k++;
            start1++;
        }
        while (start2 <= end2) {
            v2[k] = v1[start2];
            k++;
            start2++;
        }
        for (k = start; k <= end; k++) {
            v1[k] = v2[k];
        }
    }

    /*
     * 桶排序：将值为i的元素放入i号桶，最后依次把桶里的元素倒出来。
     * 桶排序序思路：
     * 1. 设置一个定量的数组当作空桶子。
     * 2. 寻访序列，并且把项目一个一个放到对应的桶子去。
     * 3. 对每个不是空的桶子进行排序。
     * 4. 从不是空的桶子里把项目再放回原来的序列中。
     * 假设数据分布在[0，100)之间，每个桶内部用链表表示，在数据入桶的同时插入排序，然后把各个桶中的数据合并。
     * */

    struct ListNode {
        int val;
        ListNode* next;
        explicit ListNode(int x = 0)
            :val(x)
            ,next(nullptr)
        {}
    };

    static ListNode* insert(ListNode* head, int key) {
        ListNode dummyNode;
        ListNode* newNode = new ListNode(key);
        ListNode* pre, *cur;
        pre = &dummyNode;
        cur = head;
        while (nullptr != cur && cur->val <= key) {
            pre = cur;
            cur = cur->next;
        }
        newNode->next = cur;
        pre->next = newNode;
        return dummyNode.next;
    }

    static ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode dummyNode;
        ListNode* dummy = &dummyNode;
        while (nullptr != head1 && nullptr != head2) {
            if (head1->next <= head2->val) {
                dummy->next = head2;
                head2 = head2->next;
            }
            dummy = dummy->next;
        }
        if (nullptr != head1) {
            dummy->next = head1;
        }
        if (nullptr != head2) {
            dummy->next = head2;
        }
        return dummyNode.next;
    }

    static void bucketSort(vector<int>& v) {
        int size = v.size();
        vector<ListNode*> buckets(BUCKETNUM, (ListNode*)(0));
        for (int i = 0; i < size; i++) {
            int index = v[i] / BUCKETNUM;
            ListNode* head = buckets.at(index);
            buckets.at(index) = insert(head, v[i]);
        }
        ListNode* head = buckets.at(0);
        for (int i = 1; i < BUCKETNUM; i++) {
            head = merge(head, buckets.at(i));
        }
        for (int i = 0; i < size; i++) {
            v[i] = head->val;
            head = head->next;
        }
    }
    
    /*
     * 插入排序思路：
     * 1. 从第一个元素开始，该元素可以认为已经被排序
     * 2. 取出下一个元素，在已经排序的元素序列中从后向前扫描
     * 3. 如果该元素（已排序）大于新元素，将该元素移到下一位置
     * 4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
     * 5. 将新元素插入到该位置后
     * 6. 重复步骤2~5
     * */

    static void insertSort(vector<int>& v) {
        int size = v.size();
        for (int i = 1; i < size - 1; i++) {
            int tmp = v[i];
            for (int j = i - 1; j >= 0; j--) {
                if (v[i] > tmp) {
                    v[j + 1] = v[j];
                    v[j] = tmp;
                } else {
                    break;
                }
            }
        }
    }

    static void heapSort();

    /*
     * 计数排序：统计小于等于该元素值的元素的个数i，于是该元素就放在目标数组的索引i位（i≥0）。
     * 计数排序基于一个假设，待排序数列的所有数均为整数，且出现在（0，k）的区间之内。
     * 如果 k（待排数组的最大值） 过大则会引起较大的空间复杂度，一般是用来排序 0 到 100 之间的数字的最好的算法，但是它不适合按字母顺序排序人名。
     * 计数排序不是比较排序，排序的速度快于任何比较排序算法。
     * 时间复杂度为 O（n+k），空间复杂度为 O（n+k）
     * 算法的步骤如下：
     * 1. 找出待排序的数组中最大和最小的元素
     * 2. 统计数组中每个值为 i 的元素出现的次数，存入数组 C 的第 i 项
     * 3. 对所有的计数累加（从 C 中的第一个元素开始，每一项和前一项相加）
     * 4. 反向填充目标数组：将每个元素 i 放在新数组的第 C[i] 项，每放一个元素就将 C[i] 减去 1
     * */

    static void countSort(vector<int>& v, vector<int> vObj) {
        //确保待排序列非空
        if (v.empty()) {
            return;
        }

        //使用 v 的最大值 + 1作为计数容器 vCount 的大小
        int vCountLength = (*max_element(begin(v), end(v))) + 1;
        vector<int> vCount(vCountLength, 0);

        //统计每个键值出现的次数
        for (int i = 0; i < v.size(); i++) {
            vCount[v[i]]++;
        }

        //后面的键值出现的位置为前面所有键值出现的次数之和
        for (int i = 1; i < vCountLength; i++) {
            vCount[i] += vCount[i - 1];
        }

        //将键值放到目标位置
        //此处逆序是为了保持相同键值的稳定性
        for (int i = v.size(); i > 0; i--) {
            vObj[--vCount[v[i - 1]]] = v[i - 1];
        }
    }

    /*
     * 希尔排序：每一轮按照事先决定的间隔进行插入排序，间隔会依次缩小，最后一次一定要是1。
     * */

    static void shellSort(vector<int>& v) {
        int h = 1;
        int size = v.size();
        while (h < size / 3) {
            h = 3 * h + 1;
        }
        while (h >= 1) {
            for (int i = h; i < size; i ++) {
                for (int j = i; j >= h && v[j] < v[j - h]; j -= h) {
                    int tmp = v[j];
                    v[j] = v[j - h];
                    v[j - h] = tmp;
                }
            }
            h = h / 3;
        }
    }
    
    /*
     * 快速排序思路：
     * 1. 选取第一个数为基准
     * 2. 将比基准小的数交换到前面，比基准大的数交换到后面
     * 3. 对左右区间重复第二步，直到各区间只有一个数
     * */

    static void quickSort(vector<int>& v, int low, int high) {
        if (low >= high) {  //递归出口
            return;
        }
        int first = low;
        int last = high;
        int key = v[first]; //设第一个为基准
        while (first < last) {
            while (first < last && v[last] >= key) {    //比基准小的移到基准前面
                last--;
            }
            if (first < last) {
                v[first] = v[last];
                first++;
            }
            while (first < last && v[first] <= key) {   //比基准大的移到基准后面
                first++;
            }
            if (first < last) {
                v[last] = v[first];
                last--;
            }
        }
        v[first] = key; //基准置位
        quickSort(v, low, first - 1);   //递归排序前基准值半部分
        quickSort(v, first + 1, high);  //递归排序基准值后半部分
    }

    /*
     * 基数排序：一种多关键字的排序算法，可用桶排序实现。
     * */

    static int maxbit(vector<int>& v, int size) {
        int maxData = v[0];
        for (int i = 1; i < size; i++) {
            if (maxData < v[i]) {
                maxData = v[i];
            }
        }
        int d = 1;
        int p = 10;
        while (maxData >= p) {
            maxData = maxData / 10;
            d++;
        }
        return d;
    }

    static void radixSort(vector<int>& v, int size) {
        int d = maxbit(v, size);
        int* tmp = new int[size];
        int* count = new int[10];
        int i, j, k;
        int radix = 1;
        for (i = 1; i <= d; i++) {
            for (j = 0; j < 10; j++) {
                count[j] = 0;
            }
            for (j = 0; j < size; j++) {
                k = (v[j] / radix) % 10;
                count[k]++;
            }
            for (j = 1; j < 10; j++) {
                count[j] = count[j - 1];
            }
            for (j = size - 1; j >= 0; j--) {
                k = (v[j] / radix) % 10;
                tmp[count[k] - 1] = v[j];
                count[k]--;
            }
            for (j = 0; j < size; j++) {
                v[j] = tmp[j];
            }
            radix = radix * 10;
        }
        delete[] tmp;
        delete[] count;
    }
};
