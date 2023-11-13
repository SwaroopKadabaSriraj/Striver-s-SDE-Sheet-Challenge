/*codetudio anwer*/

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int solve(TreeNode<int> *root,int &dia){
    if(!root)return -1;
    int left=1+solve(root->left,dia);
    int right=1+solve(root->right,dia);
    dia=max(dia,left+right);
    return max(left,right);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int dia=0;
    solve(root,dia);
    return dia;
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
    int rec(TreeNode* root, int &d) {
        if(root == NULL) return 0;
        int ld = rec(root->left, d);
        int rd = rec(root->right, d);
        d=max(d,ld+rd);
        return max(ld,rd)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        rec(root, d);
        return d;
    }
};
