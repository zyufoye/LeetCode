#include<vector>
#include <iostream>
using namespace std;

void insert_sort(vector<int> &nums,int n) {
    for(int i=0 ; i<n ; i++) {
        for(int j=i; j>0 && nums[j]<nums[j-1] ; j--) {
            swap(nums[j],nums[j-1]);
        }
    }
}
int main() {
    vector<int> a = {0,4,5,8,12,98,65,1,2,84,9};
    insert_sort(a,11);
    for(int i:a) {
        cout<<i<<" ";
    }
    return 0;
}
