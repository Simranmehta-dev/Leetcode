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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=1;
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});

        while(!q.empty()){
           int min=q.front().second;
           int size=q.size();
           int first,last;
           for(int i=0;i<size;i++){
               int cid=q.front().second-min;
               TreeNode* temp=q.front().first;
               q.pop();
               if(i==0)first=cid;
               if(i==size-1)last=cid;
               if(temp->left)q.push({temp->left,(long long)2*cid+1});
               if(temp->right)q.push({temp->right,(long long)2*cid+2});
              

              
           }
            ans=max(ans,last-first+1);
        }

        return ans;
    }
};