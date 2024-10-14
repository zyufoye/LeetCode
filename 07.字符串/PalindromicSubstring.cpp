#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

int extendSubstrings(string s,int l,int r) {
    int count=0;
    while(l>=0 && r<s.length() && s[l]==s[r]) {
        l--;
        r++;
        ++count;
    }
    return count;
}

int countSubstrings(string s) {
    int counts=0;
    for(int i=0;i<s.length();i++) {
        counts+=extendSubstrings(s,i,i);//计算奇数长的的回文字符串
        counts+=extendSubstrings(s,i,i+1);//计算偶数长度的回文字符串
    }
    return counts;
}

int main() {
    string s="aaa";
    int sum=countSubstrings(s);
    cout<<sum<<endl;
    return 0;
}