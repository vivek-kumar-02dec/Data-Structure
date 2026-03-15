class Fancy {
public:
    long long mod = 1e9+7;
    vector<long long> nums;
    long long mul = 1, add = 0;

    long long modPow(long long a,long long b){
        long long res=1;
        while(b){
            if(b&1) res=(res*a)%mod;
            a=(a*a)%mod;
            b>>=1;
        }
        return res;
    }

    long long modInv(long long x){
        return modPow(x,mod-2);
    }

    Fancy() {}

    void append(int val) {
        long long v = ((val - add + mod) % mod * modInv(mul)) % mod;
        nums.push_back(v);
    }

    void addAll(int inc) {
        add = (add + inc) % mod;
    }

    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }

    int getIndex(int idx) {
        if(idx >= nums.size()) return -1;
        return (nums[idx] * mul + add) % mod;
    }
};
