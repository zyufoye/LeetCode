#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max_chunk =0 , sum=0;
        for (int i=0; i<arr.size();i++) {
            max_chunk = max(max_chunk,arr[i]);
            if (max_chunk == i) {
                sum++;
            }
        }
        return sum;
    }
};
int main() {
    vector<int> a = {1,0,2,3,4};
    int sum=0;
    Solution solution;
    sum = solution.maxChunksToSorted(a);
    cout<<sum<<endl;
    return 0;
}