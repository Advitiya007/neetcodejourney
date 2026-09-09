class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xori=0;
        for(auto x:nums){
            xori^=x;
        }
        return xori;
    }
};
