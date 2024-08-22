#include <algorithm>
#include<iostream>
#include <numeric>
#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> num(n,1);
        if(n<2) {
            return n;
        }
        for (int i=1;i<n;i++) {
            if(ratings[i]>ratings[i-1]) {
                num[i]=num[i-1]+1;
            }
        }
        for(int i=n-1;i>0;i--) {
            if(ratings[i-1]>ratings[i]) {
                num[i-1]=max(num[i]+1,num[i-1]);
            }
        }
        return accumulate(num.begin(),num.end(),0);
    }
};
int main() {
    Solution solution;
    vector<int> s={1,2,4,3};
    cout<<solution.candy(s)<<endl;
    return 0;
}