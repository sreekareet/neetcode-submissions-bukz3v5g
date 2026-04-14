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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<vector<int>> result;

        if(!root) return result;

        q.push(root);

        while(!q.empty()){
            int level = q.size();
            vector<int>currLevel;
            for(int i = 0; i < level; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                currLevel.push_back(node->val);
            }
            result.push_back(currLevel);
        }
        return result;
    }
};
