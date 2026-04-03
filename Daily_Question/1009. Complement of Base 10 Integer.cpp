class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int sum=0;
        int base=1;
        while(n){ // untile n not eaquals to 0
            sum+=base*(!(n&1));
            n>>=1;
            base*=2;
        }
        return sum;
    }
};
