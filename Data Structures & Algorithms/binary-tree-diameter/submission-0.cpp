/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int dfs(TreeNode* root , int &maxi){
        if(!root) return 0;

        int left = dfs(root->left,maxi);
        int right = dfs(root->right,maxi);

        maxi = max(maxi , 1 + left + right);

        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        int el = dfs(root,maxi);
        return maxi-1;
    }
};
