#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        for (int i=0;i<s.size();i++) {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
                str.push(s[i]);
            }else {
                if(str.empty()) {
                    return false;
                }
                if ((str.top() == '{' && s[i] == '}') ||
                    (str.top() == '[' && s[i] == ']') ||
                    (str.top() == '(' && s[i] == ')')) {
                        str.pop();
                        }else {
                            return false;
                        }

            }
        }
        return str.empty();
    }
};

int main() {
    string s  = "()[]{}}";
    Solution solution;
    cout<<solution.isValid(s)<<endl;
    return 0;
}
