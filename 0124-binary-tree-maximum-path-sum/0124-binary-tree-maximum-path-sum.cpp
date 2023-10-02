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
     int func(TreeNode* root,int &maxi){
        if(root==NULL){
            return 0;
        }
        int lh=func(root->left,maxi);
        int rh=func(root->right,maxi);
        if(lh<0){
            lh=0;
        }
        if(rh<0){
            rh=0;
        }
        maxi=max(maxi,lh+rh+root->val);

        return root->val+max(lh,rh);
    }
public:
    int maxPathSum(TreeNode* root) {
         int maxi=INT_MIN;
      
        int x=func(root,maxi);
          return maxi;
    }
};