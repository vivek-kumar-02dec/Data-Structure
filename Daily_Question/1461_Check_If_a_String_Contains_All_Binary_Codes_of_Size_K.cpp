class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        if(k>n) return false;
        int need=1<<k;
        unordered_set<string> mp;
        mp.reserve(min(need,n));
        for(int i=0;i+k<=n;i++){
            mp.insert(s.substr(i,k));
            if(mp.size()==need) return true;
        }
        return false;
    }
};
