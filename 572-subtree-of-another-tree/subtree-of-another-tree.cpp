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
    bool dfs(TreeNode* root1,TreeNode* root2){
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;

        if(root1->val!=root2->val){
            return false;
        }

        bool ans1 = dfs(root1->left,root2->left);
        bool ans2 = dfs(root1->right,root2->right);

        return ans1&&ans2;

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        bool ans=false;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp!=NULL && temp->val==subRoot->val){
                ans=dfs(temp,subRoot);
                if(ans) return ans;
            }
            if(temp==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
            }

            if(temp!=NULL && temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp!=NULL && temp->right!=NULL){
                q.push(temp->right);
            }
        }
        return ans;

    }
};