/*
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 *
 * 本题中，一棵高度平衡二叉树定义为：
 *
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * */
#include <iostream>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
/*
 * 先计算当前节点左右子树的高度，如果
 * 大于 1 返回 false，否则返回 true
 * 再继续判断左右节点
 * */

class SolutionOne {
public:
    bool result = true;
public:
    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return result;
    }
private:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {  //递归直到 root == nullptr，因为空树是平衡二叉树
            return result;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if (abs(left - right) > 1) {
            result = false;
        }
        return 1 + std::max(left, right);
    }
};
/*
 * 执行用时 : 28 ms, 在Balanced Binary Tree的C++提交中击败了93.99% 的用户
 * 内存消耗 : 17.4 MB, 在Balanced Binary Tree的C++提交中击败了19.87% 的用户
 * */
