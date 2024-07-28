class Solution {
public:
    vector<vector<int>> ans;
    void bt(int k, int n, int currSum, int idx, vector<int>& curr)

    {
        if (curr.size() > k)
            return;
        if (currSum == n && curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        for (int i = idx; i <= 9; i++) {
            curr.push_back(i);
            bt(k, n, currSum + i, i + 1, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        bt(k, n, 0, 1, curr);
        return ans;
    }
};