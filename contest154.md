### 1189. Maximum Number of Balloons
https://leetcode.com/contest/weekly-contest-154/problems/maximum-number-of-balloons/  
```
class Solution(object):
    def maxNumberOfBalloons(self, text):
        """
        :type text: str
        :rtype: int
        """
        if not text:
            return 0
        d = collections.defaultdict(int)
        vis = collections.defaultdict(bool)
        
        vis['b'] = False
        vis['a'] = False
        vis['l'] = False
        vis['o'] = False
        vis['n'] = False
        
        for ch in text:
            d[ch] += 1
        
        nums = []
        for key in d:
            if key in ['b','a','l','o','n']:
                vis[key] = True
                if key == 'l' or key == 'o':
                    nums.append(d[key] // 2)
                else:
                    nums.append(d[key])
        
        complete = True
        for ch in vis:
            if vis[ch] == 0:
                complete = False
                break
        # print(d)
        # print(vis)
        if complete:
            return min(nums) if len(nums) != 0 else 0
        return 0
```

### 1190. Reverse Substrings Between Each Pair of Parentheses 
https://leetcode.com/contest/weekly-contest-154/problems/reverse-substrings-between-each-pair-of-parentheses/  
```
class Solution(object):
    def reverseParentheses(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return None
        stack = []  # stack
        ans = ""
        n = len(s)
        
        # 从第一个左括号开始
        i = 0
        pre = ""
        while i < n:
            if s[i] == '(':
                break
            pre += s[i]
            i += 1
        # print('first pass: ', ans)
        if i >= n-1:
            return pre
        
        k = n-1
        tail = ""
        while k >= 0:
            if s[k] == ')':
                break
            tail = s[k] + tail
            k -= 1
            
        # print('second pass: ', tail)
        
        for j in range(i, k):
            if s[j] == ')':
                tmp = ""
                while stack and stack[-1] != '(':
                    cur = stack.pop()
                    tmp += cur
                stack.pop()  # pop '('
                if len(stack) == 0:
                    pre += tmp
                else:
                    for ch in tmp:
                        stack.append(ch)
            elif s[j] == '(':
                stack.append(s[j])
            else:
                if len(stack) == 0:
                    pre += s[j]
                else:
                    stack.append(s[j])
                    
        # print('thrid pass: ', stack)
        
        while stack:
            if stack[-1] != '(':
                ans += stack[-1]
            stack.pop()
        
        ans += tail
        ans = pre + ans
        return ans
```
### 1191. K-Concatenation Maximum Sum  
https://leetcode.com/contest/weekly-contest-154/problems/k-concatenation-maximum-sum/  
```
Given an integer array arr and an integer k, modify the array by repeating it k times.

For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

As the answer can be very large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: arr = [1,2], k = 3
Output: 9
Example 2:

Input: arr = [1,-2,1], k = 5
Output: 2
Example 3:

Input: arr = [-1,-2], k = 7
Output: 0
 

Constraints:

1 <= arr.length <= 10^5
1 <= k <= 10^5
-10^4 <= arr[i] <= 10^4
```
### 5192. Critical Connections in a Network  
https://leetcode.com/contest/weekly-contest-154/problems/critical-connections-in-a-network/     
一道经典的模板题，顺道学习怎么找强连通分量，找割边，找割点。  
```
There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
 

Constraints:

1 <= n <= 10^5
n-1 <= connections.length <= 10^5
connections[i][0] != connections[i][1]
There are no repeated connections.

```
