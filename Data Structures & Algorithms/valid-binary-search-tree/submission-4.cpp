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
    using ll = long long;
    bool dfs(TreeNode* root , ll low , ll high){
        if(!root) return true;

        if(root->val <= low || root->val >= high) return false;

        return dfs(root->left,low,root->val) && dfs(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) {
        ll low = LLONG_MIN;
        ll high = LLONG_MAX;

        return dfs(root,low,high);
    }
};
