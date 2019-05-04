/*
 * 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，
 * 两个二叉树的一些节点便会重叠。
 * 你需要将他们合并为一个新的二叉树。
 * 合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，
 * 否则不为 NULL 的节点将直接作为新二叉树的节点。
 * */
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
/*
 * 合并必须从根节点开始
 * */

/*
 * 不修改原二叉树解法
 * */
class SolutionOne {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return nullptr;
        }
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        //申请一个新节点，其值为两个数节点之和，接着递归
        TreeNode* root = new (TreeNode)(t1->val + t2->val); 
        //先合并根节点，再合并左右子树
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);
        return root;
    }
};

/*
 * 执行用时 : 92 ms, 在Merge Two Binary Trees的C++提交中击败了42.37% 的用户
 * 内存消耗 : 19 MB, 在Merge Two Binary Trees的C++提交中击败了35.91% 的用户
 * */

/*
 * 在原二叉树的基础上进行修改
 * */
class SolutionTwo {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return nullptr;
        }
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};
/*
 * 执行用时 : 60 ms, 在Merge Two Binary Trees的C++提交中击败了88.85% 的用户
 * 内存消耗 : 13.5 MB, 在Merge Two Binary Trees的C++提交中击败了89.09% 的用户
 * */
