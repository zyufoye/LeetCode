from typing import List
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return len(nums)
        else:
        # 逻辑存在bug，无法处理[1,1,1,2,2,3]这种情况，因为根据k进行修正后，
        # 会存在[1,1,2,2,2,3] 这种情况，在处理第2个2的时候，会因为前面修改了状态，而产生影响

        # 原因，代码写错了，应该跟已保留区的元素做对比，不应该跟已处理过的元素做对比
        # 修改 if nums[i] != nums[i-2] : 为 if nums[i] != nums[k-2] :
            k = 2
            
            for i in range(2,len(nums)):
                if nums[i] != nums[k-2] :
                    nums[k] = nums[i]
                    k += 1
            return k
        # 用指针思路可以解决，无需修改数组元素
        # else:
        #     slow , fast = 2,2
        #     while fast < len(nums):
        #         if nums[fast] != nums[slow-2]:
        #             nums[slow] = nums[fast]
        #             slow += 1
        #         fast += 1
        #     return nums[:slow],slow
       


nums = [0,0,1,1,1,1,2,3,3]
nums1 = [1,1,1,2,2,3]
print(Solution().removeDuplicates(nums1))