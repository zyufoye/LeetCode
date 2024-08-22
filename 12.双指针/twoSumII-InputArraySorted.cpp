#include<vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers,int target) {
        int l=0,r=numbers.size()-1,sum;
        while (l<r) {
            sum = numbers[l]+numbers[r];
            if(sum == target) {
                break;
            }
            if(sum>target) {
                r--;
            }else {
                l++;
            }
        }
        return vector<int>{l+1,r+1};
    }
};

int main() {
    vector<int> a={2,7,11,15},b;
    int target = 9;
    Solution solution;
    b=solution.twoSum(a,target);
    for(int i:b) {
        cout<<i<<" ";
    }
    return 0;
}
