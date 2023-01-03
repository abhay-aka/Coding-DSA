class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        arr = list(range(1,10))
        def backtrack(start, target, temp):
            if target == 0 and len(temp) == k:
                res.append(temp[:])
                return
            for i in range(start, len(arr)) :
                temp.append(arr[i])
                backtrack(i+1, target-arr[i], temp)
                temp.pop()

        backtrack(0,n,[])
        return res