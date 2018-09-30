class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> m;
        for (auto e : deck) ++m[e];
        auto comp_val = [](auto i, auto j) { return i.second < j.second; };
        int mi = min_element (m.begin (), m.end (), comp_val)->second;
        if (mi < 2) return false;
        for (int j = 2; j <= mi; ++j) {
            auto div_j = [j](auto i) { return i.second % j == 0; };
            if (all_of (m.begin (), m.end (), div_j)) return true;   
        }
        return false;        
    }
};
