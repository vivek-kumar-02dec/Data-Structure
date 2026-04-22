class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(string st:queries){
            for(string dic:dictionary){
            int c=0;
                for(int i=0;i<dic.size();i++){
                    if(st[i]!=dic[i]) c++;
                }
                if(c<=2) {
                    ans.push_back(st);
                    break;
                }
            }
        }
        return ans;
    }
};
