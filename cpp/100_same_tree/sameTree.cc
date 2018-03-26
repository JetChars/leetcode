// C/C++ File
// AUTHOR:   JetChars
// FILE:     sameTree.cc
// ROLE:     TODO (some explanation)
// CREATED:  2018-03-26 21:04:24
// MODIFIED: 2018-03-26 21:53:35

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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(random()%2) return isSameTree1(p, q);
        return isSameTree2(p, q);
    }

    bool isSameTree1(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (p && q && p->val == q->val){
          return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return false;
    }

    bool isSameTree2(TreeNode* p, TreeNode* q) {

        std::queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while (q1.size()>0 && q2.size()>0){
            auto x = q1.front();
            q1.pop();
            auto y = q2.front();
            q2.pop();
            if (!x && !y) continue;
            if (x && y && x->val == y->val){
                q1.push(x->left);
                q1.push(x->right);
                q2.push(y->left);
                q2.push(y->right);
            }
            else return false;
        }
        return true;
    }
};
