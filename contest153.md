# Contest 153
## 5181. Distance Between Bus Stops
没什么，理解题意就做出来了。虽然做的时候很憨，写错了for循环的位置。
```
class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        cand1, cand2 = 0, 0
        if destination < start:
            start, destination = destination, start
            
        for i in range(start, destination):
            cand1 += distance[i]
        
        n = len(distance)
        for j in range(destination, n):
            cand2 += distance[j]
        for k in range(0, start):
            cand2 += distance[k]       
        return min(cand1, cand2)
```
然后聪明的做法其实是：
```
class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        if destination < start:
            start, destination = destination, start
        tot, this_way = sum(distance), sum(distance[start:destination])
        return min(this_way, tot - this_way)
```
## 5183. Day of the Week
用库函数可以直接过。
## 5182. Maximum Subarray Sum with One Deletion 
比较有意思的一道题，相似的题可以参见53. Maximum Subarray。我的思路是先整个数组求一遍最大，然后依次去掉一个元素求一遍最大，然后取最大里面最大的，但是TLE了，代码：
```
static int n=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int solve(vector<int>& arr) {
        int ans = INT_MIN;
        int max_here = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            max_here = max(arr[i], max_here+arr[i]);
            ans = max(ans, max_here);
        }
        return ans;
    }
    
    int maximumSum(vector<int>& arr) {
        int cand = solve(arr);
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            vector<int> cur(arr);
            cur.erase(cur.begin() + i);
            cand = max(cand, solve(cur));
        }
        return cand;
    }
};
```
比较科学的搞法是先正着算一遍最大，再倒着算一遍最大，去掉一个的最大就等于```front[i-1] + back[i+1]```，然后最大里取最大：
## 5184. Make Array Strictly Increasing
Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
```
Example 1:

Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
Example 2:

Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
Example 3:

Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.
If there is no way to make arr1 strictly increasing, return -1.
```
