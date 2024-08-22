#include<vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1,int m,vector<int>& nums2,int n) {
        int pos = m-- + n-- -1;
        while (m>=0 && n>=0) {
            nums1[pos] = nums1[m]>nums2[n] ? nums1[m--]:nums2[n--];
            pos--;
        }
        while(n>=0) {
            nums1[pos--] = nums2[n--];
        }
    }
};
int main() {
    vector<int> a={1,2,3,0,0,0};
    vector<int> b={2,5,6};
    int m=6,n=3;
    Solution solution;
    solution.merge(a,3,b,3);
    for(int i:a) {
        cout<<i<<" ";
    }
    return 0;
}