
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;

        return p->val == q->val &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if (!subroot) return true;
        if (!root) return false;

        if (isSameTree(root, subroot)) return true;

        return isSubtree(root->left, subroot) ||
               isSubtree(root->right, subroot);
    }
};
