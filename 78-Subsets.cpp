class Solution {
public:
    void backtrack(int start, std::vector<int>& nums, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        result.push_back(current);
        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            backtrack(i + 1, nums, current, result);
            current.pop_back();
        }
    }

    vector<std::vector<int>> subsets(std::vector<int>& nums) {
        vector<std::vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
};