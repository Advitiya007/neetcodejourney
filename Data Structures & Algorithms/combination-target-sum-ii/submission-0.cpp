class Solution {
   public:
    void solve(vector<int>& nums, vector<int>& veci, vector<vector<int>>& ans, int target, int sum,
               int indx, int n) {
        if (sum == target) {
            ans.push_back(veci);
            return;
        }
        if (indx == n || sum > target) return;

        for (int k = indx; k < n; k++) {
            //   if (i > idx && candidates[i] == candidates[i - 1]) {
            //         continue;
        
        if (k > indx && nums[k] == nums[k - 1]) continue;
        if (sum + nums[k] > target) {
            break;
        }
        veci.push_back(nums[k]);
        solve(nums, veci, ans, target, sum + nums[k], k + 1, n);
        veci.pop_back();
    }

    // solve(nums , target+arr[indx]);

}

vector<vector<int>>
combinationSum2(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    vector<int> veci;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    solve(nums, veci, ans, target, 0, 0, n);
    return ans;
}
}
;
