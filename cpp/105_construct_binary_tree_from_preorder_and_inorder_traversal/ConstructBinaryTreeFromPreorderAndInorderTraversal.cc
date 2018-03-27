// C/C++ File
// AUTHOR:   jetchars
// FILE:     ConstructBinaryTreeFromPreorderAndInorderTraversal.cc
// ROLE:     TODO (some explanation)
// CREATED:  2018-03-27 23:43:54
// MODIFIED: 2018-03-28 00:27:22
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        auto root = new TreeNode(inorder[0]);
        int pos = 0;
        if(preorder.size() == 0) return NULL;
        for (; pos < preorder.size(); pos++) {
            if(preorder[pos] == root->val){
                vector<int> pl(preorder.begin(), preorder.begin()+pos);
                vector<int> pr(preorder.begin()+pos+1, preorder.end());
                vector<int> il(inorder.begin()+1, preorder.begin()+pos+1);
                vector<int> ir(inorder.begin()+pos+1, inorder.end());
                root->left = buildTree(pl, il);
                root->right = buildTree(pr, ir);
            }
        }
        return &root;
    }
};
