#include<vector>
#include <iostream>
#include <bits/shared_ptr_base.h>
using namespace std;

void bubble_sort(vector<int> &nums,int n) {
    bool swapped;
    for(int i=1 ; i < n;i++) {
        swapped = false;
        for(int j=1;j<n-i+1;j++) {
            if(nums[j] < nums[j-1]) {
                swap(nums[j],nums[j-1]);
                swapped = true;
            }
        }
        if(!swapped) {
            break;
        }
    }
}

int main() {
    vector<int> a = {0,4,5,8,12,98,65,1,2,84,9};
    bubble_sort(a,11);
    for(int i:a) {
        cout<<i<<" ";
    }
    return 0;
}