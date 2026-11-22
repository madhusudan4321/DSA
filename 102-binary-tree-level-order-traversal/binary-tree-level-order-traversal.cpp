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
    vector<vector<int>>ans;
    void bfs(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        ans.push_back({root->val});
        vector<int>vec;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node!=NULL && node->left!=NULL){
                vec.push_back(node->left->val);
            }
            if(node!=NULL && node->right!=NULL){
                vec.push_back(node->right->val);
            }
            if(node==NULL){
                if(!vec.empty()){
                    ans.push_back(vec);
                    q.push(NULL);
                }
                vec.clear();
                continue;
            }
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        bfs(root);
        return ans;
    }
};