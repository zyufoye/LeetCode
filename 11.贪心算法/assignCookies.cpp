#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int child =0,cookie=0;
        while(child < g.size() && cookie < s.size()) {
            if(g[child] <= s[cookie])child++;
            cookie++;
        }
        return child;
    }
};

int main() {
    vector<int> g ={1,2,3,4,6,7,10};
    vector<int> s ={2,3,4,5,6};
    Solution solution;
    cout<<solution.findContentChildren(g,s);
    return 0;
}