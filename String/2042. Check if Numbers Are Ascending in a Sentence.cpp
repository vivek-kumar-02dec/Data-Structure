class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev=-1;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                int sum=0;
                while(i<n && isdigit(s[i])){
                    sum=(sum*10)+s[i]-'0';
                    i++;
                }
                if(sum<=prev) return false;
                prev=sum;
            }
        }
        return true;
    }
};
