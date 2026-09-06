class Solution {
public:
void solve(vector<int>&nums ,vector<int>&taken , vector<int> &veci , vector<vector<int>>&ans , int n  ){
if(veci.size()==n) {ans.push_back(veci); return;}

for( int i= 0 ; i < n ; i++){
    if(taken[i]==0){
        taken[i]=1;
        veci.push_back(nums[i]);
        solve( nums , taken ,veci,  ans , n );
        taken[i]=0;
        veci.pop_back();
    }
}

}
    vector<vector<int>> permute(vector<int>& nums) {
        map< int , int> mapi;
        int n = nums.size();
        vector<int>taken( n, 0);
        vector<vector<int>>ans;
            vector<int> veci;
        solve(nums , taken ,veci, ans , n );
        return ans;

    }
};
