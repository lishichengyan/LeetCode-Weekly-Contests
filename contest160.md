## Q1
https://leetcode.com/contest/weekly-contest-160/problems/find-positive-integer-solution-for-a-given-equation/  
easy
## Q2
https://leetcode.com/contest/weekly-contest-160/problems/circular-permutation-in-binary-representation/  
考了格雷码  
```
def getGray(self, n) -> list:
    codes = []
    if n == 1:
        codes.append('0')
        codes.append('1')
        return codes
    last = self.getGray(n-1)

    for i in range(len(last)):
        codes.append('0' + last[i])
    for i in range(len(last)-1, -1, -1):
        codes.append('1' + last[i])
    return codes

def circularPermutation(self, n: int, start: int) -> List[int]:
    codes = self.getGray(n)
    nums = []
    for code in codes:
        nums.append(int(code, 2))
    pos = nums.index(start)
    ans = []
    ans = nums[pos:] + nums[:pos]
    return ans
```
## Q3  
https://leetcode.com/contest/weekly-contest-160/problems/maximum-length-of-a-concatenated-string-with-unique-characters/  
dfs
## Q4 
https://leetcode.com/contest/weekly-contest-160/problems/tiling-a-rectangle-with-the-fewest-squares/   
没看  

