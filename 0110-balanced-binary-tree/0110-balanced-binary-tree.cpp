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
    int height(TreeNode* root){
        //base case
        if(root == NULL) return 0;
        //left subtree ki height
        int left = height(root->left);
        //left subtree unbalanced
        if(left == -1) return -1;
        //right subtree ki height
        int right = height(root->right);
        //right subtree unbalanced
        if(right == -1) return -1;
        //current node unbalanced
        if(abs(left-right) > 1) return -1;
        //return height
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

/*nt height(TreeNode* root,int &diff){
        if(root == NULL) return 0;
        int left = height(root->left,diff);
        int right = height(root->right,diff);
        diff = max(diff,abs(left - right));
        return  max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        int diff = 0;
        height(root,diff);
        return diff <= 1;
*/ //another way to solve this problem