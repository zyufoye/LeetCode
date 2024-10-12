## 0x00 回溯法
回溯法是优先搜索的一种特殊情况，又称为试探法，常用于需要记录节点状态的深度优先搜索。通常来说，排列、组合、选择类问题使用回溯法比较简单。  
回溯法的核心是回溯，当搜索到某一节点时，我们发现当前节点及其子节点并不是需求目标时，就需要回退到原来的节点继续搜索，并且还原该节点的初始状态。这样的好处是我们可以始终只对图的总状态进行修改，而非每次遍历时都需要新建一个图来存储状态。  
在具体的写法上，它与普通的深度优先搜索一样，都要：  
\[修改当前节点状态]→\[递归子节点]  
不同的是多了回溯的步骤，变成了：  
\[修改当前节点状态]→\[递归子节点]→\[回改当前节点状态]。  
回溯的诀窍：  
一是按引用传递，二是所有修改的状态在递归完成后回改。

## 0x01 全排列组合
请输出1，2，3的全排列组合。  
```C++
// 主函数
vector<vector<int>> permute(vector<int>& nums) {
vector<vector<int>> ans;
backtracking(nums, 0, ans);
return ans;
}
// 辅函数
void backtracking(vector<int> &nums, int level, vector<vector<int>> &ans) {
if (level == nums.size() - 1) {
ans.push_back(nums);
return;
}
for (int i = level; i < nums.size(); i++) {
swap(nums[i], nums[level]); // 修改当前节点状态
backtracking(nums, level+1, ans); // 递归子节点
swap(nums[i], nums[level]); // 回改当前节点状态
}
}
```
假设有三条路径，abc，第一轮选择，有三个选择，所以i从0到2，当level+1=1时，就剩下两个选择了，同理当level为2时，就只剩下一个选择，递归结束一轮。