// 1652. Defuse the Bomb
class Solution {
public:
    void solve(vector<int>& code, vector<int>& nums, int k) {
        int n=code.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int x = 1; x <= k; x++) {
                sum += code[(i + x) % n];
            }
            nums.push_back(sum);
        }
    }
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> nums;
        if(k==0) return vector<int>(n,0);
        if (k < 0){
            reverse(code.begin(),code.end());
            k=-k;
            solve(code,nums,k);
            reverse(nums.begin(),nums.end());
        }
        else solve(code, nums, k);
        return nums;
    }
};
