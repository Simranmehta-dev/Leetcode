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
    void preorder(vector<int>&a,TreeNode* p){
    //     if(p==NULL){
    //         return;
    //     }
    //    if(p->val==NULL){
    //         a.push_back(INT_MIN);
    //    }
    //    else{
    //         a.push_back(p->val);
    //    }
    //     preorder(a,p->left);
    //     preorder(a,p->right);

         if (p == nullptr) {
            a.push_back(INT_MIN); // or any other sentinel value to represent NULL nodes
        } else {
            a.push_back(p->val);
            preorder(a, p->left);
            preorder(a, p->right);
        }
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>a1;
        vector<int>a2;

        preorder(a1,p);
        preorder(a2,q);

        if(a1.size()!=a2.size()){
            return false;
        }

        for(int i=0;i<a1.size();i++){
            if(a1[i]!=a2[i]){
                return false;
            }
        }
        
        return true;

    }
};