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
    int diff = INT_MAX;
    TreeNode* prev = NULL;
    void traversal(TreeNode* root){
        if(root==NULL) return;

        traversal(root->left);
        if(prev!=NULL){
            diff = min(diff,abs(root->val-prev->val));
        }
        prev = root;
        traversal(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        traversal(root);
        return diff;
    }
};