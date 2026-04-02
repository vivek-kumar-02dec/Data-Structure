class Solution {
public:
    bool check(char s){
        switch(s){
            case 'a': return true;
            case 'e': return true;
            case 'i': return true;
            case 'o': return true;
            case 'u': return true;
            default: return false;
        }
        
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        // vector<int> ind;
        int maxi=0;
        deque<int> ind;
        for(int i=0;i<n;i++){
            if(check(s[i]))
                ind.push_back(i);
            while(!ind.empty() && ind.front() < i - k + 1)
                ind.pop_front();
            maxi=max(maxi,(int)ind.size());
        }
        return maxi;
    }
};
