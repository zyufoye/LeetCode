#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
    stack<int> in,out;
public:
    MyQueue() {

    }

    void push(int x) {
        in.push(x);
    }

    void reverse() {
        if(out.empty()) {
            while(!in.empty()) {
                int x = in.top();
                in.pop();
                out.push(x);
            }
        }
    }

    int pop() {
        reverse();
        int x = out.top();
        out.pop();
        return x;
    }

    int peek() {
        reverse();
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};

int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    cout<<queue.peek()<<endl;
    cout<<queue.pop()<<endl;
    cout<<queue.peek()<<endl;
    cout<<queue.empty()<<endl;
    return 0;
}
