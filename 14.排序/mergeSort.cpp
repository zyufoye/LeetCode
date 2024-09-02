#include<vector>
#include <iostream>
using namespace std;

void merge_sort(vector<int>& nums,int l,int r,vector<int>& temp) {
    if(l+1>=r) {
        return;
    }
    //划分
    int m = l +(r-l)/2; //计算中间位置为r-l
    merge_sort(nums,l,m,temp);
    merge_sort(nums,m,r,temp);
    //合并
    int p=l,q=m,i=l;
    while(p<m || q<r) {
        if(q >= r || (p<m && nums[p]<=nums[q])) {
            temp[i++] = nums[p++];
        }else {
            temp[i++] = nums[q++];
        }
    }
    for(i=l;i<r;i++) {
        nums[i] = temp[i];
    }
}

int main() {
    vector<int> a={0,4,5,8,12,98,65,1,2,84,9};
    //注意此处设置的temp数组大小尽量合待排序数组一样大
    vector<int> b(a.size());
    merge_sort(a,0,a.size(),b);
    for(int i:a) {
        cout<<i<<" ";
    }
    return 0;
}
