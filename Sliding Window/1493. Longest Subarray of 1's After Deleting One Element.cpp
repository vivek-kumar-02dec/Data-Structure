class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int curr=0,prev=0;
        int maxi=0;
        bool del=false;
        for(int n:nums){
            if(n==0){
                del=true;
                int sum=curr+prev;
                maxi=max(maxi,sum);
                prev=curr;
                curr=0;
            }
            else curr++;
        }
        int sum=curr+prev;
        maxi=max(maxi,sum);
        return del?maxi:maxi-1;
    }
};
