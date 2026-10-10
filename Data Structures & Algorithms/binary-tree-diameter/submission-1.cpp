class Solution {
public:
    int dfs(TreeNode* root, int& maxi) {
        if (!root) return 0;

        int left = dfs(root->left, maxi);
        int right = dfs(root->right, maxi);

        maxi = max(maxi, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        dfs(root, maxi);
        return maxi;
    }
};

//time compl :  O(n);
// space compl : O(h);