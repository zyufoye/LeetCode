#include<vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> heap;

    //获得最大值
    int top() {
        return heap[0];
    }

    //插入任意值：把新数字放在最后一位，然后上浮
    void push(int k) {
        heap.push_back(k);
        swim(heap.size()-1);
    }
    //删除最大值：把最后一个数字放在堆顶，然后下沉
    void pop() {
        heap[0] = heap.back();
        heap.pop_back();
        sink(0);
    }
    //上浮
    void swim(int pos) {
        while (pos > 0 && heap[pos] > heap[(pos-1)/2]) {
            swap(heap[pos],heap[(pos-1)/2]);
            pos = (pos-1)/2;
        }
    }
    //下沉
    void sink(int pos) {
        int N = heap.size();
        while (2*pos +1 < N) {
            int i = 2*pos +1;
            if (i + 1 < N && heap[i] < heap[i + 1]) {
                i++; // 如果右子节点存在且更大，则 i 指向右子节点
            }
            if(heap[pos]>=heap[i])break;
            swap(heap[pos], heap[i]); // 交换当前节点与较大子节点的位置
            pos = i; // 更新当前节点的位置
        }
    }
};