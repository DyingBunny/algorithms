/*
 * 给定一个二叉树，检查它是否是镜像二叉树
 * */

#include <queue>
using std::queue;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
/*递归算法*/

/*
 * 如果一个树的左子树与右子树镜像对称，那么这个树是对称的。
 *
 * 镜像二叉树要求：
 * 它们的两个根结点具有相同的值。
 * 每个树的右子树都与另一个树的左子树镜像对称。
 * */

class SolutionOne {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isSymmetic(root->left, root->right);
    }
private:
    bool isSymmetic(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) {   //两者都为空树，则为 true
            return true;
        }
        if (t1 == nullptr || t2 == nullptr) {   //两者有一个为空树，则为 false
            return false;
        }
        if (t1->val != t2->val) {   //两者都存在，且节点值不同 false
            return false;
        }
        return isSymmetic(t1->left, t2->right) && isSymmetic(t1->right, t2->left);
    }
};
/*
 * 执行用时 : 16 ms, 在Symmetric Tree的C++提交中击败了96.01% 的用户
 * 内存消耗 : 14.8 MB, 在Symmetric Tree的C++提交中击败了82.35% 的用户
 * */

/*方法二*/

/*迭代算法*/

/*
 * 方法二：迭代
 * 除了递归的方法外，我们也可以利用队列进行迭代。
 * 队列中每两个连续的结点应该是相等的，而且它们的子树互为镜像。
 * 最初，队列中包含的是 root 以及 root。
 * 该算法的工作原理类似于 BFS，但存在一些关键差异。
 * 每次提取两个结点并比较它们的值。然后，将两个结点的左右子结点按相反的顺序插入队列中。
 * 当队列为空时，或者我们检测到树不对称（即从队列中取出两个不相等的连续结点）时，该算法结束。
 * */

/*
 * 复杂度分析
 * 时间复杂度：O(n)。
 * 因为我们遍历整个输入树一次，所以总的运行时间为 O(n)，其中 nn 是树中结点的总数。
 * 空间复杂度：搜索队列需要额外的空间。
 * 在最糟糕的情况下，我们不得不向队列中插入 O(n) 个结点。
 * 因此，空间复杂度为 O(n)。
 * */

class SolutionTwo {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(root);
        while (!Q.empty()) {
            TreeNode* t1 = Q.front();
            Q.pop();
            TreeNode* t2 = Q.front();
            Q.pop();
            if (t1 == nullptr && t2 == nullptr) {
                continue;
            }
            if (t1 == nullptr || t2 == nullptr) {
                return false;
            }
            if (t1->val != t2->val) {
                return false;
            }
            Q.push(t1->left);
            Q.push(t2->right);
            Q.push(t1->right);
            Q.push(t2->left);
        }
        return true;
    }
private:
};

/*
 * 执行用时 : 16 ms, 在Symmetric Tree的C++提交中击败了96.01% 的用户
 * 内存消耗 : 15.1 MB, 在Symmetric Tree的C++提交中击败了77.41% 的用户
 * */
