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
private:
    TreeNode* build(vector<int>& inorder, vector<int>& preorder, int &preIdx, int left, int right, unordered_map<int,int>& pos) {
        if (left > right) return nullptr;

        int val = preorder[preIdx++];
        TreeNode* root = new TreeNode(val);
        int idx = pos[val];

        root->left = build(inorder, preorder, preIdx, left, idx - 1, pos);
        root->right = build(inorder, preorder, preIdx, idx + 1, right, pos);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // hashmap to store indexes of inorder values
        int n = inorder.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }
        
        int preIdx = 0;
        int left = 0, right = n - 1;

        TreeNode* root = build(inorder, preorder, preIdx, left, right, pos);
        return root;
    }
};