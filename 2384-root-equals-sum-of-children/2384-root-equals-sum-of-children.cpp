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
    bool checkTree(TreeNode* root) {
        long long r=root->val;
         long long l=0;
          long long ri=0;
        if(root->left)
         l=root->left->val;
       
        if(root->right)
         ri=root->right->val;

        if(r==(l+ri)){
            return true;
        }
        return false;
    }
};