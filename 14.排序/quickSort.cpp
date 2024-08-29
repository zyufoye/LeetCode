#include<vector>
#include <iostream>
using namespace std;

void quick_sort(vector<int> &nums,int l,int r) {
    if(l+1>=r) {
        return;
    }
    int first=l , last=r-1,key=nums[first];
    while (first < last) {
        while (first < last && nums[last] >= key) {
            --last;
        }
        nums[first] = nums[last];
        while (first < last && nums[first] <= key) {
            ++first;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort(nums,l,first);
    quick_sort(nums,first+1,r);
}

int main() {
    vector<int> a={0,4,5,8,12,98,65,1,2,84,9};
    quick_sort(a,0,a.size());
    for(int i:a) {
        cout<<i<<" ";
    }
    return 0;
}
