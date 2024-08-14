#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(const int& num:nums) {
            //利用数组结构建立一个桶，获取vector中的每个元素，把对应位置的元素变负
            int pos = abs(num) - 1;
            if (nums[pos]>0) {
                nums[pos] = -nums[pos];
            }
        }
        //遍历调整后的数组，找出缺失元素
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>0) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;

    vector<int> nums1 = {4,3,2,7,8,2,3,1};
    vector<int> result1 = solution.findDisappearedNumbers(nums1);

    cout << "Test Case 1 - Missing numbers: ";
    for(int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
