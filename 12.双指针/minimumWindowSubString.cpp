#include<vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> chars(128,0);
        vector<bool> flag(128,false);
        //统计t中的字符情况
        for(int i=0;i<t.size();i++) {
            flag[t[i]] =true;
            chars[t[i]]++;
        }
        //移动滑动窗口，不断更改统计数据
        int cnt=0,l=0,min_l=0,min_Size=s.size()+1;
        for(int r=0;r<s.size();r++) {
            if(flag[s[r]]) {
                if(--chars[s[r]]>=0) {
                    ++cnt;
                }
                //若目前滑动窗口已包含t中全部字符，则开始尝试将l右移，争取获得最小子串
                while (cnt == t.size()) {
                    if(r-l+1<min_Size) {
                        min_l = l;
                        min_Size = r-l+1;
                    }
                    if(flag[s[l]] && ++chars[s[l]]>0) {
                        --cnt;
                    }
                    l++;
                }
            }
        }
        return min_Size>s.size()?"":s.substr(min_l,min_Size);
    }
};

int main() {
    Solution solution;
    // 测试用例
    string S1 = "ADOBECODEBANC";
    string T1 = "ABC";
    string result1 = solution.minWindow(S1, T1);
    cout << "Test Case 1: " << result1 << endl;
    // 期望输出: "BANC"
    return 0;
}