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
    int dfs(TreeNode* root){
        if(root==NULL) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);
        
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)) return true;
        TreeNode* temp = root;

        int h1 = dfs(root->left);
        int h2 = dfs(root->right);

        if(abs(h1-h2)>1){
            return false;
        }
        
        bool ans1 = isBalanced(temp->left);
        bool ans2 = isBalanced(temp->right);
        
        return ans1&&ans2;
    }
};