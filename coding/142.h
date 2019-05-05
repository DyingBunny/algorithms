/*
 * 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
 * 如果 pos 是 -1，则在该链表中没有环。
 * 说明：不允许修改给定的链表。
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
 * 解法如下：
 *
 * 首先分别定义两个指针，一个一次走两步，一个走一步，分别为fast，slow，
 * 记录下快指针经过的结点数（不包括头结点）为lf，慢指针为ls，必有lf = 2ls；
 * 
 * 假设有环链表的长度为l，环的长度为c，从头结点到环入口的距离为a；
 * 
 * 一个走得快，一个走得慢，且路程中有环，则必定会相遇，且lf - ls = c，设相遇时的点距离环入口为x；
 * 
 * 根据以上变量定义和关系，我们可以得出下列等式：
 * 
 * 头结点到环入口的距离+环的长度-1=链表长，这个大家画图就明白了，即l = a + c - 1 (1)；
 * 
 * 快指针走过的距离=链表长+1+相遇点到环入口的距离，画图就知道了，即lf = l + 1 + x (2)；
 * 
 * 慢指针走过的距离=头结点到环入口的距离+相遇点到环入口的距离，这个显然，即ls = a + x (3)；
 * 
 * 结合式(2)，式(3)，且lf = 2ls，所以l = 2a + x - 1 (4)；
 * 
 * 联立式(4)和式(1)，得到a = c - x (5)
 * 
 * 式(5)用人话说就是，头结点到到环入口的距离 = 环长 - 相遇点到环入口的距离；
 * 
 * 也就是让慢指针从头结点开始走，让快指针从相遇点开始走，都是一次走一步，下次相遇点就是环入口
 * */

class SolutionOne {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* meetingNode = MeetingNode(head);
        if (meetingNode == nullptr) {
            return nullptr;
        }
        int nodesInLoop = 1;
        ListNode* pNode1 = meetingNode;
        while (pNode1->next != meetingNode) {
            pNode1 = pNode1->next;
            ++nodesInLoop;
        }
        pNode1 = head;
        for (int i = 0; i < nodesInLoop; ++i) {
            pNode1 = pNode1->next;
        }
        ListNode* pNode2 = head;
        while (pNode1 != pNode2) {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        return pNode1;
    }
protected:
    ListNode* MeetingNode(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* slow = head->next;
        if (slow == nullptr) {
            return nullptr;
        }
        ListNode* fast = slow->next;
        while (fast != nullptr && slow != nullptr) {
            if (fast == slow) {
                return fast;
            }
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            }
        }
        return nullptr;
    }
};
/*
 * 执行用时 : 28 ms, 在Linked List Cycle II的C++提交中击败了47.07% 的用户
 * 内存消耗 : 9.7 MB, 在Linked List Cycle II的C++提交中击败了47.27% 的用户
 * */
