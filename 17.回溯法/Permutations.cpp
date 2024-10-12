#include <iostream>
using namespace std;
#include <vector>

void backtracking(vector<int>& nums,int level,vector<vector<int>>& ans) {
    if(level == nums.size()-1) {
        ans.push_back(nums);
        return;
    }
    for(int i=level;i<nums.size();i++) {
        swap(nums[i],nums[level]);
        backtracking(nums,level+1,ans);
        swap(nums[i],nums[level]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    backtracking(nums,0,ans);
    return ans;
}

void print2DVector(const vector<vector<int>>& ans) {
    for(const vector<int>& vec : ans) {
        for(int num : vec) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

int main() {
    vector<int> nums={1,2,3};
    vector<vector<int>> ans;
    ans=permute(nums);
    print2DVector(ans);
    return 0;
}