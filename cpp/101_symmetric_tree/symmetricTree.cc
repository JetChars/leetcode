// C/C++ File
// AUTHOR:   JetChars
// FILE:     symmetricTree.cc
// ROLE:     TODO (some explanation)
// CREATED:  2018-03-26 22:03:01
// MODIFIED: 2018-03-27 13:36:15
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
    Solution(){
       srand(time(NULL));
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        if(random()%2) return isSymmetric1(root->left, root->right);
        return isSymmetric2(root->left, root->right);
    }

    bool isSymmetric1(TreeNode* left, TreeNode* right) {
        if(!left && !right) return true;
        if(left && right && left->val == right->val){
            return isSymmetric1(left->left, right->right) &&
                   isSymmetric1(left->right, right->left);
        }
        return false;
    }
// time: O(n), space: O(logn)
    bool isSymmetric2(TreeNode* left, TreeNode* right) {
        std::queue<TreeNode*> l, r;
        l.push(left);
        r.push(right);
        while(l.size()>0 && r.size()>0){
            auto x = l.front();
            l.pop();
            auto y = r.front();
            r.pop();
            if(!x && !y) continue;
            if(x && y && x->val == y->val){
                l.push(x->left);
                l.push(x->right);
                r.push(y->right);
                r.push(y->left);
            }
            else return false;
        }
        return true;
    }
};
