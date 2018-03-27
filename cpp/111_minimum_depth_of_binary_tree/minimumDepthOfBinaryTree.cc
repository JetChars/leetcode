// C/C++ File
// AUTHOR:   jetchars
// FILE:     minimumDepthOfBinaryTree.cc
// ROLE:     TODO (some explanation)
// CREATED:  2018-03-27 23:20:38
// MODIFIED: 2018-03-27 23:43:00
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
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && root->right) {
            return minDepth(root->right) + 1;
        }
        else if(!root->right && root->left) {
            return minDepth(root->left) + 1;
        }
        else if(root->right && root->left) {
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }
        else return 1;
    }
};
