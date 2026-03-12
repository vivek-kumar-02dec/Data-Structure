#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

struct DSU {
    vector<int> p;
    int c;
    DSU(int n) : p(n), c(n) { iota(p.begin(), p.end(), 0); }
    int find(int i) { return p[i] == i ? i : p[i] = find(p[i]); }
    bool unite(int i, int j) {
        int r1 = find(i), r2 = find(j);
        if (r1 != r2) { p[r1] = r2; c--; return 1; }
        return 0;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        auto check = [&](int X) {
            DSU dsu(n);
            int upgrades = 0, mandatory_count = 0;
            vector<vector<int>> opt;
            
            for (auto& e : edges) {
                if (e[3] == 1) { // mandatory
                    if (e[2] < X) return false;
                    if (!dsu.unite(e[0], e[1])) return false; // Cycle in mandatory edges
                    mandatory_count++;
                } else opt.push_back(e);
            }
            
            if (mandatory_count > n - 1) return false;

            // Greedily add optional edges that don't need upgrades
            for (auto& e : opt) if (e[2] >= X) dsu.unite(e[0], e[1]);
            
            // Use upgrades for edges that reach X when doubled
            for (auto& e : opt) {
                if (dsu.find(e[0]) != dsu.find(e[1]) && e[2] < X && 2 * e[2] >= X && upgrades < k) {
                    dsu.unite(e[0], e[1]);
                    upgrades++;
                }
            }
            return dsu.c == 1;
        };

        int low = 0, high = 2e5, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) { ans = mid; low = mid + 1; }
            else high = mid - 1;
        }
        return ans;
    }
};
