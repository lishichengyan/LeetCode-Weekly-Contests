# Weekly Contest 180
## 1380. Lucky Numbers in a Matrix
https://leetcode.com/contest/weekly-contest-180/problems/lucky-numbers-in-a-matrix/  
1. 暴力。自己的代码可以再优化一下，找每行最小和每列最大可以放到一个嵌套的for循环里做
2. `zip(*matrix)`求转置
小结：https://leetcode.com/problems/lucky-numbers-in-a-matrix/discuss/540593/Python3-Two-solutions%3A-set-intersection-and-comparing-with-minmax  
## 1381. Design a Stack With Increment Operation
https://leetcode.com/problems/design-a-stack-with-increment-operation/  
1. increment O(n) 解很简单
2. increment可以O(1)做掉。being lazy is more efficient!  
3. pop的时候，inc之前的贡献要加到下一级
小结：https://leetcode.com/problems/design-a-stack-with-increment-operation/discuss/539716/JavaC%2B%2BPython-Lazy-increment-O(1)  
## 1382. Balance a Binary Search Tree
https://leetcode.com/contest/weekly-contest-180/problems/balance-a-binary-search-tree/  
1. 与lc107类似，多了一个中序遍历
小结：https://leetcode.com/problems/balance-a-binary-search-tree/discuss/542027/Python3-Similar-to-LeetCode108-recursion-%2B-inorder-traversal  
## 1383. Maximum Performance of a Team 
https://leetcode.com/problems/maximum-performance-of-a-team/  
1. 贪心（一开始选efficiency最高的）
2. 然后逐步淘汰，当堆里的人数等于k，就开除掉速度最慢的，看看新加进来的人能不能增加收益  
小结：https://leetcode.com/problems/maximum-performance-of-a-team/discuss/542193/Python3-Share-my-heapq-implementation


