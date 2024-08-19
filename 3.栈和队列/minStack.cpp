#include<iostream>
#include<stack>
using namespace std;
class MinStack {
    stack<int> s,min_s;
public:
    MinStack() {

    }

    void push(int val) {
        if(min_s.empty() || min_s.top() >= val) {
            min_s.push(val);
        }
        s.push(val);
    }

    void pop() {
        if(!min_s.empty() && min_s.top() == s.top()) {
            min_s.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min_s.top();
    }
};

int main() {
    MinStack stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(0);
    cout<<stack1.getMin()<<endl;
    stack1.pop();
    cout<<stack1.getMin()<<endl;
    return 0;
}