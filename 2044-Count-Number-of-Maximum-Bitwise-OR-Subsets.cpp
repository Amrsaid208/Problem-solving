class Solution {
public:
    int ans = 0;
    void calculatSubSets(vector<int> &nums, int curr, int maxOr, int idx) {
        if (curr == maxOr) {
            ans++;
        }

        for (int i = idx; i < nums.size(); i++) {
            calculatSubSets(nums, curr | nums[i], maxOr, i + 1);
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int &num : nums) {
            maxOr |= num;
        }
        calculatSubSets(nums, 0, maxOr, 0);
        return ans;
    }
};