/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
         queue<TreeNode*>q;
         q.push(root);

         while(!q.empty()){
             TreeNode* curr=q.front();
             q.pop();

             if(curr->left){
                 parent[curr->left]=curr;
                 q.push(curr->left);
             }
             if(curr->right){
                 parent[curr->right]=curr;
                 q.push(curr->right);
             }
         }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;//keep pointer to a node's parent
        markParent(root,parent);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int curr_level=0;
        while(!q.empty()){
            int size=q.size();
            if(curr_level++ == k)break;
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !vis[current->left]){
                    q.push(current->left);
                    vis[current->left]=true;
                }
                if(current->right && !vis[current->right]){
                    q.push(current->right);
                    vis[current->right]=true;
                }
                if(parent[current] && !vis[parent[current]] ){
                   q.push(parent[current]);
                   vis[parent[current]]=true;
                }
            }
        }
        vector<int>result;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            result.push_back(curr->val);
        }
        return result;
    }
};