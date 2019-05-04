/*
 * 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 这一个节点和这个节点的所有子孙。
 * */

#include <queue>
using std::queue;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
class SolutionOne {
public:
    bool isSubTree(TreeNode* s, TreeNode* t) {
        if (s == nullptr) {
            return false;
        }
        return isSubTreeWithRoot(s, t) || isSubTree(s->left, t) || isSubTree(s->right, t);
    }
private:
    bool isSubTreeWithRoot(TreeNode* s, TreeNode* t) {
        if (t == nullptr && s == nullptr) {
            return true;
        }
        if (t == nullptr || s == nullptr) {
            return false;
        }
        if (t->val != s->val) {
            return false;
        }
        return isSubTreeWithRoot(s->left, t->left) && isSubTreeWithRoot(s->right, t->right);
    }
};
