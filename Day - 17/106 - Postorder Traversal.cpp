/*CodeStudio solution*/

/*
Following is the structure of Tree Node

class TreeNode 
{
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
*/
#include<bits/stdc++.h>
vector<int> postorderTraversal(TreeNode* root)
{
    // Write your code here	
    vector<int> nodes;
    stack<TreeNode*> todo;
    TreeNode* last = NULL;
    while (root || !todo.empty()) {
        if (root) {
            todo.push(root);
            root = root -> left;
        } else {
            TreeNode* node = todo.top();
            if (node -> right && last != node -> right) {
                root = node -> right;
            } else {
                nodes.push_back(node -> val);
                last = node;
                todo.pop();
            }
        }
    }
    return nodes;
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        TreeNode* last = NULL;
        while (root || !todo.empty()) {
            if (root) {
                todo.push(root);
                root = root -> left;
            } else {
                TreeNode* node = todo.top();
                if (node -> right && last != node -> right) {
                    root = node -> right;
                } else {
                    nodes.push_back(node -> val);
                    last = node;
                    todo.pop();
                }
            }
        }
        return nodes;
    }
};
