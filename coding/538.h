/*
 * 给定一个二叉搜索树，把它转化为累加树，使得每个节点的值是原来节点的值加上所有大于它的节点值之和
 * 例如：
 * 5    2   13 转化后
 * 18   20  13
 * */

#include <stack>
using std::stack;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
/*
 * 以右根左的顺序遍历二叉搜索树，将遍历的前一个节点的值累加记录起来，得到当前节点的值
 * */
/*递归写法*/
class SolutionOne {
public:
    TreeNode* convertBST(TreeNode* root) {
        MyconvertBST(root, sum);
        return root;
    }
private:
    void MyconvertBST(TreeNode* root, int& sum) {
        if (root == nullptr) {  //空树直接返回
            return;
        }
        MyconvertBST(root->right, sum);  //先遍历右子树
        sum += root->val;   
        root->val = sum;    //当前根节点的值为自身的值加上右节点的值
        MyconvertBST(root->left, sum);
    }
private:
    int sum;
};
/*非递归写法*/
class SolutionTwo {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        stack<TreeNode*> S;
        TreeNode* node = root;
        while (node != nullptr || !S.empty()) {
            while (node != nullptr) {
                S.push(node);
                node = node->right;
            }
            node = S.top();
            S.pop();
            node->val += sum;
            sum = node->val;
            if (node->left != nullptr) {
                node = node->left;
            } else {
                node = nullptr;
            }
        }
        return root;
    }
private:
    int sum;
};
