# contest 156
## 5205. Unique Number of Occurrences
https://leetcode.com/contest/weekly-contest-156/problems/unique-number-of-occurrences/    
哈希表+set搞定
## 5207. Get Equal Substrings Within Budget  
https://leetcode.com/contest/weekly-contest-156/problems/get-equal-substrings-within-budget/  
转换成数字数组，然后滑动窗口  
```
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        # if maxCost <= 0:
        #     return 1
        arr = []
        tot = len(s)
        for i in range(tot):
            arr.append(abs(ord(s[i]) - ord(t[i])))
        # print(arr)
        
        i, j = 0, 0
        cur = 0  # 当前和
        ans = 0  # 答案
        while j < tot:
            cur += arr[j]
            if cur > maxCost:
                cur -= arr[i]
                i += 1
            ans = max(ans, j-i+1)
            j += 1
        return ans
```
## 5206. Remove All Adjacent Duplicates in String II  
https://leetcode.com/contest/weekly-contest-156/problems/remove-all-adjacent-duplicates-in-string-ii/  
栈，想到了，但是写错了。唉。。。   
正确做法是每次只去push和pop栈顶，避免受前面出现过的元素的影响。   
```
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = []
        for c in s:
            if not stack:
                stack.append([c, 1])
            elif stack[-1][0] != c:
                stack.append([c, 1])
            elif stack[-1][1] + 1 < k:
                stack[-1][1] += 1
            else:
                stack.pop()
        
        ans = []
        for c,ct in stack:
            ans.extend([c] * ct)
        return "".join(ans)
```
## 5208. Minimum Moves to Reach Target with Rotations  
https://leetcode.com/contest/weekly-contest-156/problems/minimum-moves-to-reach-target-with-rotations/   
直接没看。应该是搜索...  
