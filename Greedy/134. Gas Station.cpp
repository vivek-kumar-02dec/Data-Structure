class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int str=0, cst = 0,total=0;
        for (int i = 0; i < cost.size(); i++) {
            total+=gas[i]-cost[i];
            cst += gas[i] - cost[i];
            if (cst < 0) {
                cst = 0;
                str = i + 1;
            }
        }
        return total >= 0 ? str : -1;
    }
};
