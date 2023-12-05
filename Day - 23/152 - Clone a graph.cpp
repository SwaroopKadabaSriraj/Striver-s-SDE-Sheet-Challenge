/*CodeStudio solution*/

/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
void dfs(graphNode* node,graphNode* root,vector<graphNode*> &visited){
    for(auto n:node->neighbours){
        if(visited[n->data]==NULL){
            graphNode* newNode=new graphNode(n->data);
            visited[n->data]=newNode;
            (root->neighbours).push_back(newNode);
            dfs(n,newNode,visited);
        }
        else (root->neighbours).push_back(visited[n->data]);
    }
}

graphNode *cloneGraph(graphNode *node)
{
    if(!node)return node;
    vector<graphNode*> visited(100005,NULL);
    graphNode* root=new graphNode(node->data);
    visited[node->data]=root;
    dfs(node,root,visited);
    return root;
}

/*Leetcode solution*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


class Solution {
    unordered_map <Node*, Node*> clone;
public:
    Node* cloneGraph(Node* node) {
        if (!node) 
            return NULL;
        if (clone.count(node))
            return clone[node];
        Node* foo = new Node(node->val);
        clone[node] = foo;
        for (auto n : node->neighbors) {
            foo->neighbors.push_back(cloneGraph(n)); 
        }
        return foo;
    }
};
