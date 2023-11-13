/*CodeStudio solution*/


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

bool path(TreeNode<int> *root, vector<int> &arr, int &n){
    if(!root)return false;
    arr.push_back(root->data);
    if(root->data==n)return true;
    if(path(root->left,arr,n)||path(root->right,arr,n))return true;
    arr.pop_back();
    return false;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    vector<int> arr1,arr2;
    path(root,arr1,x);
    path(root,arr2,y);
    int n=arr1.size();
    int m=arr2.size();
    int i=0,j=0;
    int ans;
    while(i<n && j<m){
        if(arr1[i]==arr2[j]){
            ans=arr1[i];
        }
        i++;
        j++;
    }
    return ans;
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
        if (!root || root == p || root == q) 
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : !right ? left : root;
    }
};
