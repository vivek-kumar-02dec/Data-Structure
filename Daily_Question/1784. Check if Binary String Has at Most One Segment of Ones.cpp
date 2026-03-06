class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        bool found=false;
        int i=0;
        for(i;i<n;i++){
            int x=s[i]-'0';
            if(x==1) found=true;
            else break;
        }
        for(i;i<n;i++){
            int x=s[i]-'0';
            if(x==1) return false;
        }
        return true;
        
    }
};
