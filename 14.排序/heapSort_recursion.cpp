#include<vector>
#include <iostream>
using namespace std;

void heapSort(vector<int> &arr,int heapSize,int i) {
    int largest = i;
    int lson = 2*i+1,rson = 2*i+2;
    if(lson < heapSize && arr[lson] > arr[largest]) {
        largest = lson;
    }
    if(rson < heapSize && arr[rson] > arr[largest]) {
        largest = rson;
    }
    if(largest!=i) {
        swap(arr[largest],arr[i]);
        heapSort(arr,heapSize,largest);
    }
}
//堆排序入口
void heap_sort(vector<int>& arr,int heapSize) {
    //建堆
    for(int i=heapSize/2-1;i>=0;i--) {
        heapSort(arr,heapSize,i);
    }
    //排序
    for(int i=heapSize-1;i>0;i--) {
        swap(arr[i],arr[0]);
        heapSort(arr,i,0);
    }
}

int main() {
    vector<int> a = {0,4,5,8,12,98,65,1,2,84,9};
    heap_sort(a,11);
    for(int i:a) {
        cout<<i<<" ";
    }
    return 0;
}