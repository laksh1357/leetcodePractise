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
    int height(TreeNode* root,int &diameter){
        //base case
        if(root == NULL) return 0;
        //left height
        int left = height(root->left,diameter);
        //right height
        int right = height(root->right,diameter);
        //update diameter
        diameter = max(diameter,left + right);
        //return height
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root,diameter);
        return diameter;
        // if(root == NULL) return 0;
        // int leftDiameter = diameterOfBinaryTree(root->left);
        // int rightDiameter = diameterOfBinaryTree(root->right);
        // int currDiameter = height(root->left) + height(root->right);
        // return max(leftDiameter,max(rightDiameter,currDiameter));
    }
};

//bina diameter ke update ke O(N²) worst-case solution dega
//par after isse O(N) dega