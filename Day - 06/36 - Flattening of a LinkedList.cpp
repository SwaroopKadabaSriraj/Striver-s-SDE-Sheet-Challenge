Node* mergeTwoLists(Node* a, Node* b) {
    
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    
    return res -> bottom; 
    
}
Node *flatten(Node *root)
{
   
        if (root == NULL || root->next == NULL) 
            return root; 
        root->next = flatten(root->next); 
        root = mergeTwoLists(root, root->next); 

        return root; 
}



/*
    Problem Link: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
*/

// helper function to merge 2 sorted lists
Node *mergeLists(Node *l1, Node *l2) {
    // base cases
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    // recursive calls
    if(l1->data <= l2->data) {
        l1->bottom = mergeLists(l1->bottom, l2);
        return l1;
    }
    else {
        l2->bottom = mergeLists(l1, l2->bottom);
        return l2;
    }
}

Node *flatten(Node *root) {
    // base case
    if(!root || !root->next)
        return root;
    // recursive call
    return mergeLists(root, flatten(root->next));
}



