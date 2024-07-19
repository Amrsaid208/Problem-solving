class Solution {
public:
    vector<int> curr;
    vector<vector<int>> ans;
    void bt(vector<int>& candidates, int target, int currSum, int number,
            int idx, int mx) {
        if (idx >= mx || currSum > target)
            return;
        if (currSum == target) {
            ans.push_back(curr);
            return;
        }
        for (int i = idx; i < mx; i++) {
            curr.push_back(candidates[i]);
            bt(candidates, target, currSum + candidates[i], candidates[i], i,
               candidates.size());
            if (curr.size())
                curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        bt(candidates, target, 0, candidates[0], 0, candidates.size());
        return ans;
    }
};