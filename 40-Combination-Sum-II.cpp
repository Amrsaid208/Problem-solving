class Solution {
public:
    std::vector<std::vector<int>> ans;
    std::vector<int> curr;

    void backtrack(std::vector<int>& candidates, int target, int start, int currSum) {
        if (currSum == target) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue; // Skip duplicates

            if (currSum + candidates[i] > target) break; // Early termination

            curr.push_back(candidates[i]);
            backtrack(candidates, target, i + 1, currSum + candidates[i]);
            curr.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        backtrack(candidates, target, 0, 0);
        return ans;
    }
};