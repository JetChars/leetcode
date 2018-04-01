#-*- coding:utf-8 -*-
# AUTHOR:   JetChars
# FILE:     105_construct_binary_tree_from_preorder_and_inorder_traversal.py
# ROLE:     TODO (some explanation)
# CREATED:  2018-04-01 16:52:08
# MODIFIED: 2018-04-01 16:59:32
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder:
            return None
        node = TreeNode(preorder[0])
        pos = inorder.index(preorder[0])
        node.left = self.buildTree(preorder[1:pos+1], inorder[:pos])
        node.right = self.buildTree(preorder[pos+1:], inorder[pos+1:])
        return node
