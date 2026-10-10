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

// ask at each node if the left ht and right ht is same 
class Solution {
public:
    int maxht(TreeNode* root){
        if(!root) return 0;

        return 1 + (max(maxht(root->left) , maxht(root->right)));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int diff = abs(maxht(root->left) - maxht(root->right));
        if(diff > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
