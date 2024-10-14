#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool isAnagram(string s,string t) {
    if(s.length() != t.length()) {
        return false;
    }
    vector<int> counts(26,0);
    for(int i=0;i<s.length();i++) {
        ++counts[s[i]-'a'];
        --counts[t[i]-'a'];
    }
    for(int i=0;i<counts.size();i++) {
        if(counts[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s1 = "listen";
    string t1 = "silent";
    bool result1 = isAnagram(s1, t1);
    cout << "Test Case 1 - Result: " << (result1 ? "True" : "False") << endl;
    return 0;
}