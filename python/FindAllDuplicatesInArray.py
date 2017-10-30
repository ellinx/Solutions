"""
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
"""


class FindAllDuplicatesInArray:
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        res = []
        i = 0
        while i < len(nums):
            if nums[i] != nums[nums[i]-1]:
                tmp = nums[i]
                nums[i], nums[tmp-1] = nums[tmp-1], nums[i]
            else:
                i += 1

        for i in range(len(nums)):
            if nums[i] != i+1:
                res.append(nums[i])

        return res


# test
tmp = FindAllDuplicatesInArray()
nums = [4,3,2,7,8,2,3,1]
result = tmp.findDuplicates(nums)
print(result)