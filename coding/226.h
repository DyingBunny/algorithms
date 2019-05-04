/*
 * 翻转一棵二叉树。
 * */

#include <queue>
using std::queue;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

/*前中后序遍历都可以达到目的*/
class SolutionOne {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        //swap
        //在这一步类似于交换两个数的值
        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};

/*
 * 执行用时 : 8 ms, 在Invert Binary Tree的C++提交中击败了94.76% 的用户
 * 内存消耗 : 8.9 MB, 在Invert Binary Tree的C++提交中击败了89.88% 的用户
 * */

/*利用层序遍历-直接交换左右即可*/
class SolutionTwo {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            TreeNode* node = Q.front();
            Q.pop();
            TreeNode* rightTree = node->right;
            node->right = node->left;
            node->left = rightTree;
            if (node->left != nullptr) {
                Q.push(node->left);
            }
            if (node->right != nullptr) {
                Q.push(node->right);
            }
        }
        return root;
    }
};
/*
 * 执行用时 : 8 ms, 在Invert Binary Tree的C++提交中击败了94.76% 的用户
 * 内存消耗 : 9.2 MB, 在Invert Binary Tree的C++提交中击败了21.20% 的用户
 * */
