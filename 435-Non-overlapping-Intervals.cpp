class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 1;
        int j = 0;
        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] >= intervals[j][1]) {
                ans++;
                j = i;
            }
        }
        return intervals.size() - ans;
    }
};