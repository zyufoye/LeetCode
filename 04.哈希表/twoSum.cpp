#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums,int target) {
    //hash表，键是数组中的数值，值是该数值的索引
    unordered_map<int,int> hash;
    vector<int> ans;
    //i是当前数组的索引，nums[i]是当前的数值
    for(int i=0;i<nums.size();i++) {
        int num = nums[i];
        //使用auto简化代码，不然类型名既复杂又很长
        //unordered_map<int, int>::iterator pos = hash.find(target - num);
        //pos是一个迭代器类型
        auto pos = hash.find(target-num);
        if(pos == hash.end()) {
            hash[num]=i;
        }else {
            //pos是迭代器类型，返回 unordered_map<int, int>
            //first对应键，second对应这个键的值
            ans.push_back(pos->second);
            ans.push_back(i);
            break;
        }
    }
    return ans;
}

int main() {
    vector<int> b,a={2,7,11,15};
    b=twoSum(a,9);
    for (const int i:b) {
        cout<<i<<" ";
    }
    return 0;
}