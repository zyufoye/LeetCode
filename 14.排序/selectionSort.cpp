#include<vector>
#include <iostream>
using namespace std;

void selection_sort(vector<int> &nums, int n) {
    int index;
    for (int i=0 ; i<n-1 ; i++) {
        index = i;
        for(int j=i+1;j<n;j++) {
            if(nums[j]<nums[index]) {
                index = j;
            }
        }
        swap(nums[index],nums[i]);
    }
}
int main() {
    vector<int> a = {0,4,5,8,12,98,65,1,2,84,9};
    selection_sort(a,11);
    for(int i:a) {
        cout<<i<<" ";
    }
    return 0;
}