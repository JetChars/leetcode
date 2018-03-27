// C/C++ File
// AUTHOR:   jetchars
// FILE:     maximumDepthOfBinaryTree.cc
// ROLE:     TODO (some explanation)
// CREATED:  2018-03-27 23:16:22
// MODIFIED: 2018-03-27 23:19:34

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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
