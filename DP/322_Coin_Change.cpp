class Solution {
public:
    int coinChange(vector<int>& Coins, int amount) {
        vector<int> nums(amount+1,amount+1);
        nums[0]=0;
        for(int i=1;i<=amount;i++){
            for(int coin:coins){
                if(i-coin>=0){
                    nums[i]=min(nums[i],1+nums[i-coin]);
                }
            }
        }
        return nums[amount]>amount?-1:nums[amount];
    }
};
