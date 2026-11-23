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
    int maxi = INT_MIN;
    int dfs(TreeNode* root){
        if(root==NULL) return 0;

        int ans1 = dfs(root->left);
        int ans2 = dfs(root->right);

        maxi = max(maxi,ans1+ans2);

        return max(ans1,ans2)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        
        dfs(root);
        return maxi;
    }
};