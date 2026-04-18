class Solution {
public:
    int mirrorDistance(int n) {
        int num = 0, curr = n;
        while (n) {
            int rem = n % 10;
            num = num * 10 + rem;
            n /= 10;
        }
        return abs(num - curr);
    }
};
