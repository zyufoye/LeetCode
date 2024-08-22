#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> indicate;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++) {
            while(!indicate.empty()) {
                int pre_index = indicate.top();
                if(temperatures[i] <= temperatures[pre_index]) {
                    break;
                }
                indicate.pop();
                ans[pre_index]= i - pre_index;
            }
            indicate.push(i);
        }
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> s ={73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = solution.dailyTemperatures(s);
    cout << "Result:";
    for(int i:result) {
        cout<<i<<" ";
    }
    return 0;
}