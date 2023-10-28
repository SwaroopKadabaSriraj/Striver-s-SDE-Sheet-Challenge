/*CodeStudio solution*/

// Implement class for minStack.
#include<bits/stdc++.h>
class minStack
{
	// Write your code here.
	int Top;
    int size;
    int *mini;
    int *arr;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
            size=100000;
            Top=-1;
            arr=new int[size];
            mini=new int[size];
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            Top=Top+1;
            arr[Top]=num;
            if(Top==0)
                mini[Top]=num;
            else
                mini[Top]=min(mini[Top-1],num);    
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
            if(Top==-1)
                return -1;
            else
                return arr[Top--];
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            if(Top==-1)
                return -1;
            else
                return arr[Top];
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(Top==-1)
                return -1;
            else
                return mini[Top];
		}
};


/*Leetcode solution*/

class MinStack {
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin()) 
            s2.push(x);	    
    }
    
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    
    int top() {
	    return s1.top();
    }
    
    int getMin() {
	    return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
