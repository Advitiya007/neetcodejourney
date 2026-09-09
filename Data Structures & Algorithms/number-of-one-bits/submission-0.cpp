class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
do{
    cnt += (n&1)? 1: 0;
}while(n>>=1);
return cnt;
    }
};
