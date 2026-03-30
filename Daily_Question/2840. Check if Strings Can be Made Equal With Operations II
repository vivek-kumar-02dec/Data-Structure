class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int> mp1,mp2,temp1,temp2;
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(i&1) {
                mp1[s1[i]]++;
                temp1[s2[i]]++;
            }
            else {
                mp2[s1[i]]++;
                temp2[s2[i]]++;

            }
        }
        return mp1==temp1 && mp2==temp2;
        
    }
};
