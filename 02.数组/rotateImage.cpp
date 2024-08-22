#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp=0,n=matrix.size()-1;
        for(int i=0;i<=n/2;i++) {
            for(int j=i;j<n-i;j++) {
                temp = matrix[j][n-i];
                matrix[j][n-i] = matrix[i][j];
                matrix[i][j] = matrix[n-j][i];
                matrix[n-j][i] = matrix[n-i][n-j];
                matrix[n-i][n-j] = temp;
            }
        }
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    for(const auto& row : matrix) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // 创建一个 4x4 的矩阵
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // 打印旋转前的矩阵
    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    // 创建 Solution 对象并调用旋转函数
    Solution solution;
    solution.rotate(matrix);

    // 打印旋转后的矩阵
    cout << "Rotated matrix:" << endl;
    printMatrix(matrix);

    return 0;
}