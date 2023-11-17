/*CodeStudio solution*/

/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    if(root->data > P->data && root->data > Q->data)
        return LCAinaBST(root->left, P, Q);
    else if(root->data < P->data && root->data < Q->data)
        return LCAinaBST(root->right, P, Q);
    else
        return root;
}

/*Leetcode solution*/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root -> val > p -> val) && (root -> val > q -> val))
            return lowestCommonAncestor(root -> left, p, q);
        else if ((root -> val < p -> val) && (root -> val < q -> val))
            return lowestCommonAncestor(root -> right, p, q);
        else
            return root;
    }
};
