class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        arr = [a,b,c]
        arr.sort()
        if arr[0] == arr[1]-1 and arr[1] == arr[2]-1:
            return [0,0]
        min_tot, max_tot = 0, 0
        if arr[1] - arr[0] == 2 or arr[2] - arr[1] == 2:
            min_tot = 1
        else:
            min1 = 1 if (arr[1] - arr[0]) > 2 else 0
            min2 = 1 if (arr[2] - arr[1]) > 2 else 0
            min_tot = min1 + min2
        
        max1 = arr[1] - arr[0] - 1
        max2 = arr[2] - arr[1] - 1
        max_tot = max1 + max2
        
        return [min_tot, max_tot]
        
