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
    bool bfs(TreeNode* root){
        if(root==NULL) return false;
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root->left,root->right});
        while(!q.empty()){
            pair<TreeNode*,TreeNode*>it = q.front();
            q.pop();
            TreeNode* left = it.first;
            TreeNode* right = it.second;
            if(left==NULL && right==NULL) continue;
            if(left==NULL || right==NULL) return false;
            if(left->val != right->val){
                return false;
            }
            q.push({left->left,right->right});
            q.push({left->right,right->left});
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return bfs(root);
    }
};