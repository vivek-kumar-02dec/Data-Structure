class Solution {
public:
    string sortSentence(string s) {
        priority_queue<pair<int, string>> temp;
        int n = s.size();
        string str;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                int idx = str.back() - '0';
                int size = str.size();
                temp.push({idx, str.substr(0, size - 1)});
                str.erase();
            } else
                str += s[i];
        }
        int idx = str.back() - '0';
        int size = str.size();
        temp.push({idx, str.substr(0, size - 1)});
        string ans;
        while (!temp.empty()) {
            ans = ' ' + temp.top().second + ans;
            temp.pop();
        }
        return ans.substr(1, ans.size());
    }
};
