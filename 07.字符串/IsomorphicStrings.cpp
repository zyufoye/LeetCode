#include <iostream>
using namespace std;
#include <vector>

bool isIsomorphic(string s,string t) {
    vector<int> s_index(256,0),t_index(256,0);
    if(s.length()!=t.length()) {
        return false;
    }
    for(int i=0;i<s.length();i++) {
        if(s_index[s[i]] != t_index[t[i]]) {
            return false;
        }
        s_index[s[i]] = t_index[t[i]] = i+1;
    }
    return true;
}

int main() {
    string s="paper22",t="title11f";
    bool y = isIsomorphic(s,t);
    cout<<y<<endl;
    return 0;
}