//this is my first look of brute force approach
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            p;
        for (int it : arr) {
            int count = 0;
            int temp = it;
            while (temp) {
                count += temp & 1;
                temp >>= 1;
            }
            p.push({count, it});
        }
        vector<int> ans;
        while(!p.empty()){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};
