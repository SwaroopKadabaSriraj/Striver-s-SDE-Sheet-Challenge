/*CodeStudio solution*/

/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void leaves(TreeNode<int> *root, int &count)
{
    if(root==NULL)
        return;
    leaves(root->left, count);
    leaves(root->right, count);
    if(root->left==NULL && root->right==NULL)
        count++;
}

long long solution(TreeNode<int> *root, long long &result)
{
    if(root==NULL)
       return 0;
   long long left=solution(root->left, result);
   long long right=solution(root->right, result);
   long long temp=root->val;
   long long ans= max(temp+left, max(temp+right, left+right+temp));
   result=max(result, ans);
   return max(temp+left, temp+right);
}

 

long long int findMaxSumPath(TreeNode<int> *root)
{
   // Write your code here.
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return -1;
    int count=0;
    leaves(root, count);
    if(count==1)
        return -1;
    long long result=-1;
        solution(root, result);
    return result;
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
    int max_sum=INT_MIN;
    int max_gain(TreeNode* root)
    {
        if(!root)return 0;
        int l=max(max_gain(root->left),0);
        int r=max(max_gain(root->right),0);
        int new_price=root->val+l+r;
        max_sum=max(max_sum,new_price);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }
};
