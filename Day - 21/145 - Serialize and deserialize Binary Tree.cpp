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
void serialize(TreeNode<int>* root, ostringstream& out) {
    if (root) {
        out << root->data << ' ';
        serialize(root->left, out);
        serialize(root->right, out);
    } else {
        out << "# ";
    }
}

TreeNode<int>* deserialize(istringstream& in) {
    string val;
    in >> val;
    if (val == "#")
        return nullptr;
    TreeNode<int>* root = new TreeNode<int>(stoi(val));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
}

string serializeTree(TreeNode<int> *root)
{
    //    Write your code here for serializing the tree
    ostringstream out;
    serialize(root, out);
    return out.str();
}

TreeNode<int>* deserializeTree(string &serialized)
{
    //    Write your code here for deserializing the tree
    istringstream in(serialized);
    return deserialize(in);
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
class Codec {
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
