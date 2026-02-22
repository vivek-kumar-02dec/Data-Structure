class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        double maxi=INT_MIN;
        for(int i=0;i<k;i++){
            sum+=(double)nums[i];
        }
        maxi=max(maxi,sum/(double)k);
        int left=0;
        for(int i=k;i<nums.size();i++){
            sum-=nums[left++];
            sum+=nums[i];
            maxi=max(maxi,sum/(double)k);
        }
        return maxi;
    }
};
