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

#include<bits/stdc++.h>
class BSTiterator
{
    public:
    stack<TreeNode<int>*> order;
    BSTiterator(TreeNode<int>*root)
    {
        // write your code here
        inorder(root);
    }
    
    void inorder(TreeNode<int>* root){
        while(root != NULL){
            order.push(root);
            root = root->left;
        }    
    }

    int next()
    {
        // write your code here
        TreeNode<int>* topi = order.top();
        order.pop();
        inorder(topi->right);
        return topi->data;
    }

    bool hasNext()
    {
        // write your code here
        return !order.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/

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
class BSTIterator {
    stack<TreeNode *> myStack;
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for (; node != NULL; myStack.push(node), node = node->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:

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
    vector<int> traverse(TreeNode* root, int& ans) {
        if (!root) 
            return {INT_MAX, INT_MIN, 0};
        vector<int> left(traverse(root->left, ans)), right(traverse(root->right, ans));
        if (left.empty() || right.empty() || root->val <= left[1] || root->val >= right[0]) 
            return {};
        int curr_sum = left[2] + right[2] + root->val;
        ans = max(ans, curr_sum);
        return {min(left[0], root->val), max(right[1], root->val), curr_sum};
    }
    
    int maxSumBST(TreeNode* root) {
        int ans(0);
        traverse(root, ans);
        return max(0, ans);
    }
};
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
