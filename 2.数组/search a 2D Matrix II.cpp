#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) {
            return false;
        }
        //记录矩阵的列数
        int n = matrix[0].size();
        int i=0,j=n-1;
        while (i<matrix.size() && j>=0) {
            if(matrix[i][j] == target) {
                return true;
            } else if(matrix[i][j]>target){
                j--;
            }else {
                i++;
            }
        }
        return false;
    }
};

int main() {
    // 创建一个5x5的增序二维矩阵
    vector<vector<int>> matrix = {
        {1,  4,  7, 11, 15},
        {2,  5,  8, 12, 19},
        {3,  6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    // 创建 Solution 对象
    Solution solution;

    // 测试用例1：查找目标值 5
    int target1 = 5;
    bool result1 = solution.searchMatrix(matrix, target1);
    cout << "Target " << target1 << (result1 ? " found" : " not found") << " in matrix." << endl;

    // 测试用例2：查找目标值 20
    int target2 = 20;
    bool result2 = solution.searchMatrix(matrix, target2);
    cout << "Target " << target2 << (result2 ? " found" : " not found") << " in matrix." << endl;

    return 0;
}