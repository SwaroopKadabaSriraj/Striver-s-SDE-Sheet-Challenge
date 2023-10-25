/*CodeStudio solution*/

#include<bits/stdc++.h>
class Stack {
queue<int>q;
    int siz;
public:
    Stack() {
        siz=-1;
    }

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return (q.empty());
    }

    void push(int element) {
        siz++;
        q.push(element);
        for(int i=0;i<siz;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(!q.empty())
        {
            int popped = q.front();
            q.pop();
            siz--;
            return popped;
        }
        return -1;
    }

    int top() {



/*Leetcode solution*/

class MyStack {
public:
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        int sz = q1.size();
        q1.push(x);
        while(sz--){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int result = top();
        q1.pop();
        return result;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
        if(!q.empty())
            return q.front();
        return -1;
    }
};
