/*CodeStudio solution*/

/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void helper(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &head, BinaryTreeNode<int>* &prev)
{
    if(!root)
        return;
    helper(root->left, head, prev);
    if(prev == NULL)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    helper(root->right, head, prev);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int> *head = NULL, *prev = NULL;
    helper(root, head, prev);
    return head;
}

/*Leetcode solution*/

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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* runner = curr->left;
                while (runner->right != nullptr) runner = runner->right;
                runner->right = curr->right, curr->right = curr->left, curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};
