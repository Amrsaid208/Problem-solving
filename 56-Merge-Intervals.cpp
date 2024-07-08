class Solution {
public:
//    static bool mySort(const vector<int> &a, const vector<int> &b)
//     {
//         return a[0] < b[0];
//     }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int j=0;
        for(int i=1;i<intervals.size();i++)
        {
            
            if(intervals[i][0] <= ans.back()[1])
            {
                ans[j][1]=max(intervals[i][1],ans.back()[1]);
            }
            else {
                ans.push_back(intervals[i]);
                j++;
            }
        }
        return ans;
    }
};