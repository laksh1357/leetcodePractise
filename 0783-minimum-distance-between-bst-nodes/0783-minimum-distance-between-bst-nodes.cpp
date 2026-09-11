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
    int minDiffInBST(TreeNode* root) {
        TreeNode* curr = root;
        int prev = -1;
        int ans = INT_MAX;
        while(curr != nullptr){
            if(curr->left == nullptr){
                if(prev != -1) ans = min(ans,curr->val - prev);
                prev = curr->val;
                curr = curr->right;
            }
            else{
                TreeNode* IP = curr->left;
                while(IP->right != nullptr && IP->right != curr) IP = IP->right;
                if(IP->right == nullptr){
                    IP->right = curr;
                    curr = curr->left;
                }
                else{
                    IP->right = nullptr;
                    if(prev != -1) ans = min(ans,curr->val - prev);
                    prev = curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};