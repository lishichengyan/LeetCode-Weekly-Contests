/*
class Solution:
    def beautifulArray(self, N):
        """
        :type N: int
        :rtype: List[int]
        """
        if N==1:
            return [1]
        else:
            l=self.beautifulArray(N//2)
            r=self.beautifulArray(N-N//2)
            return [x*2 for x in l]+[x*2-1 for x in r]
*/

class Solution {
    vector<int> go(const vector<int>& a) {
        if (a.size() > 2) {
            int o = (a.size() - 1) % 2;
            vector<int> a1, a2;
            for (int i = 0; i < a.size(); ++i) {
                if (i % 2 == o) a1.push_back(a[i]); else a2.push_back(a[i]);
            }
            vector<int> ret;
            for (int x : go(a1)) ret.push_back(x);
            for (int x : go(a2)) ret.push_back(x);
            return ret;
        }
        return a;
    }
public:
    vector<int> beautifulArray(int n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) a[i] = i + 1;
        return go(a);
    }
};
