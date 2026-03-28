class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n,'#');
        char ch = 'a';
        for (int i = 0; i < n; i++) {
            if (s[i] > '#')
                continue;
            if (ch > 'z')
                return "";
            s[i] = ch;
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    s[j] = s[i];
                }
            }
            ch++;
        }
        for (int i = 0; i < n; i++) {
            // int pre=0;
            for (int j = 0; j < n; j++) {
                int pre=0;
                if (s[i] == s[j]) {
                    if (i == n - 1 || j == n - 1)
                        pre = 1;
                    else
                        pre = 1 + lcp[i + 1][j + 1];
                } else
                    pre = 0;
                if (lcp[i][j] != pre)
                    return "";
            }
        }
        return s;
    }
};
