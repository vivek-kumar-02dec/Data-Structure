class Solution {
public:
    string helper(int n) {
        if (n == 1)
            return "0";
        string curr = helper(n - 1);
        string temp = curr;
        int sz = temp.size();
        for (int i = 0; i < sz; i++) {
            if (temp[i] == '0')
                temp[i] = '1';
            else
                temp[i] = '0';
        }
        reverse(temp.begin(), temp.end());
        return curr + '1' + temp;
    }
    char findKthBit(int n, int k) {
        int x;
        for (int i = 0; i <= 20; i++) {
            if ((1 << i) + 1 > k) {
                x = i;
                break;
            }
        }

        string str = helper(x);
        return str[k - 1];
    }
};
