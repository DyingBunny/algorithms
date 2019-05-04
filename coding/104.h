/*
 * 给定一个二叉树，找出其最大深度。
 *
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 *
 * 说明: 叶子节点是指没有子节点的节点。
 * */
#include <iostream>
#include <queue>
using std::queue;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        :val(x)
        ,left(nullptr)
        ,right(nullptr)
    {}
};
/*递归*/
class SolutionOne {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return std::max(left, right) + 1;
    }
};

/*
 * 复杂度分析
 * 时间复杂度：我们每个结点只访问一次，因此时间复杂度为 O(N)， 
 * 其中 N 是结点的数量。
 * 空间复杂度：在最糟糕的情况下，树是完全不平衡的，
 * 例如每个结点只剩下左子结点，递归将会被调用 N 次（树的高度），
 * 因此保持调用栈的存储将是 O(N)。但在最好的情况下（树是完全平衡的），
 * 树的高度将是 log(N)。因此，在这种情况下的空间复杂度将是 O(log(N))。
 * */

/*
 * 执行用时 : 24 ms, 在Maximum Depth of Binary Tree的C++提交中击败了96.47% 的用户
 * 内存消耗 : 19.5 MB, 在Maximum Depth of Binary Tree的C++提交中击败了14.16% 的用户
 * */

/*迭代*/
class SolutionTwo {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        int preCount = 1;
        int pCount = 0;
        int level = 0;
        while (!Q.empty()) {
            TreeNode* tmp = Q.front();
            Q.pop();
            preCount--;
            if (tmp->left != nullptr) {
                Q.push(tmp->left);
                pCount++;
            }
            if (tmp->right != nullptr) {
                Q.push(tmp->right);
                pCount++;
            }
            if (preCount == 0) {
                preCount = pCount;
                pCount = 0;
                level++;
            }
        }
        return level;
    }
};
/*
 * 执行用时 : 24 ms, 在Maximum Depth of Binary Tree的C++提交中击败了96.47% 的用户
 * 内存消耗 : 19.3 MB, 在Maximum Depth of Binary Tree的C++提交中击败了53.36% 的用户
 * */
