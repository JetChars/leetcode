#-*- coding:utf-8 -*-
# AUTHOR:   JetChars
# FILE:     100_same_tree.py
# ROLE:     TODO (some explanation)
# CREATED:  2018-03-26 19:56:58
# MODIFIED: 2018-03-26 20:20:25

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if p is None and q is None:
            return True
        if p and q and p.val == q.val:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        return False

    def isSameTree2(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        queue = [(p, q)]
        while queue:
            x, y = queue.pop(0)
            if x is None and y is None:
                continue
            if x and y and x.val == y.val:
                queue.append((x.left, y.left))
                queue.append((x.right, y.right))
            else:
                return False

        return True


