from typing import List
class Solution:
    # 双指针思路不太会处理
    def removeElement_test1(self, nums: List[int], val: int) -> int:
        m,n = 0,len(nums)-1
        if m == n and nums[m] == val:
            return 0

        while m < n:
            if nums[m] == val and nums[n] != val:
                nums[m] = nums[n]
                m += 1
                n -= 1
            elif nums[m] == val and nums[n] == val:
                n -= 1
            else:
                m += 1
        return m+1
    def removeElement(self, nums: List[int], val: int) -> int:
        length_nums_val = 0
        for i in range(len(nums)):
            if(nums[i] == val):
                length_nums_val += 1
        length_result = len(nums) - length_nums_val
        m,n=0,len(nums)-1
        while m < length_result:
            if nums[m] == val and nums[n] != val:
                nums[m] = nums[n]
                m += 1
                n -= 1
            elif nums[m] == val and nums[n] == val:
                n -=1
            else:
                m += 1
        nums_new = nums[:length_result]
        return nums_new,len(nums_new)
    
nums1 = [3,2,2,3]
nums2 = [0,1,2,2,3,0,4,2]
nums3 = [1]
val = 3

# result_list = []
result_list,result = Solution().removeElement(nums1,val)
print(result_list,result)

# for i in range(len(nums1)):
#     print(i)
