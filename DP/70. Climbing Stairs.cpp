class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> step;
        step.push_back(1);
        step.push_back(2);
        for(int i=3;i<=n;i++){
            step.push_back(step[i-3]+step[i-2]);
        }
        return step[n-1];
        
    }
};
