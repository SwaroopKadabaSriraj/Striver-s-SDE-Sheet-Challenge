/*CodeStudio solution*/

#include<bits/stdc++.h>
class Queue {
    stack<int> s1;
    stack<int> s2;
public:
    Queue() { }

    void enQueue(int val) {
        s1.push(val);
    }

    int deQueue() {
        if(s1.empty()){
            return -1;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    int peek() {
         if(s1.empty()){
            return -1;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    bool isEmpty() {
        return s1.empty();
    }
};


/*Leetcode solution*/

class MyQueue {
public:
    stack<int>s;
    stack<int>temp;
    
    MyQueue() { }
    
    void push(int x) {
        while(!s.empty()) {
            temp.push(s.top());
            s.pop();
        }
        temp.push(x);
        while(!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        int p=s.top();
        s.pop();
        return p;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
