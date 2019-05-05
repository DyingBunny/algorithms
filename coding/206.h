/*
 * 反转一个单链表
 * */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        :val(x)
        ,next(nullptr)
    {}
};

/*
 * 迭代
 * 在遍历链表时，将当前节点的 next 指针改为指向前一个元素，由于节点没有引用其上一个节点，因此必须事先保存其前一个元素，
 * 在更新引用之前，还需要另一个指针来存储下一个节点
 * */

class SolutionOne {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

/*
 * 复杂度分析
 * 时间复杂度：O(n) 。 假设 n 是列表的长度，时间复杂度是 O(n)。
 * 空间复杂度：O(1)
 * */

/*
 * 执行用时 : 16 ms, 在Reverse Linked List的C++提交中击败了97.04% 的用户
 * 内存消耗 : 9.1 MB, 在Reverse Linked List的C++提交中击败了61.24% 的用户
 * */

/*
 * 递归
 * 递归版本稍微复杂一些，其关键在于反向工作。假设列表的其余部分已经被反转，
 * 现在我该如何反转它前面的部分？假设列表为：n1 → … → nk-1 → nk → nk+1 → … → nm → Ø
 * 若从节点 nk+1 到 nm 已经被反转，而我们正处于 nk。
 * n1 → … → nk-1 → nk → nk+1 ← … ← nm
 * 我们希望 nk+1 的下一个节点指向 nk。
 * 所以，
 * nk.next.next = nk;
 * 要小心的是 n1 的下一个必须指向 Ø 。如果你忽略了这一点，你的链表中可能会产生循环。
 * 如果使用大小为 2 的链表测试代码，则可能会捕获此错误。
 * */

class SolutionTwo {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* reversedNode = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return reversedNode;
    }
};

/*
 * 复杂度分析
 * 时间复杂度：O(n)。 
 * 假设 nn 是列表的长度，那么时间复杂度为 O(n)O(n)。
 * 空间复杂度：O(n)。 
 * 由于使用递归，将会使用隐式栈空间。递归深度可能会达到 nn 层。
 * */

/*
 * 执行用时 : 20 ms, 在Reverse Linked List的C++提交中击败了45.40% 的用户
 * 内存消耗 : 9.3 MB, 在Reverse Linked List的C++提交中击败了8.64% 的用户
 * */
