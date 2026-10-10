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

//use a bfs trav get the nested list 
// iterate over the list to get the last el

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> bfs;
        vector<int> res;
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        vector<int> temp;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == nullptr){
                bfs.push_back(temp);
                temp.clear();

                if(!q.empty()){
                    q.push(nullptr);
                }

                continue;
            }

            temp.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        for(auto it : bfs){
            int sz = it.size();
            res.push_back(it[sz-1]);
        }

        return res;
    }
};
