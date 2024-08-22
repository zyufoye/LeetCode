#include<vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        int l=1,r=x,mid,sqrt;
        while(l<=r) {
            mid = l + (r-l)/2;
            sqrt = x/mid;
            if(sqrt==mid) {
                return sqrt;
            }else if(sqrt>mid) {
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        return r;
    }
};

int main() {
    int x = 15;
    Solution solution;
    cout<<solution.mySqrt(x)<<endl;
    return 0;
}
