from typing import List
import collections
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        result_num = {}
        for i in nums:
            if i in result_num:
                result_num[i] += 1
            else:
                result_num[i] = 1
        for i in result_num:
            if result_num[i] > len(nums)/2:
                return i
            
    # 官方解体思路：哈希表 用哈希表来快速统计每个元素出现的次数
    # 我们使用哈希映射（HashMap）来存储每个元素以及出现的次数。对于哈希映射中的每个键值对，键表示一个元素，值表示该元素出现的次数。
    def majorityElement_hashmap(self, nums: List[int]) -> int:
        counts = collections.Counter(nums)
        return max(counts.keys(), key=counts.get)
#  max(iterable, key=函数) 的灵活性就在于：
# iterable：你要比较的对象（列表、字典的 keys、字符串、集合……）
# key：定义比较标准（可以是内置函数 len、abs，也可以是字典的 get，甚至是自定义函数）
# 所以 max([1,2,3], key=counts.get) 其实只是 “用字典的 value 来决定谁最大” 的一个应用。






nums = [2,2,1,1,1,2,2]
nums = [3,2,3]
print(Solution().majorityElement_hashmap(nums=nums))