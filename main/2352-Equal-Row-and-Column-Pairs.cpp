class Solution {
public:
bool compareArrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    // Check if they have the same length
    if (arr1.size() != arr2.size()) {
        return false;
    }
    // Compare each element
    for (size_t i = 0; i < arr1.size(); ++i) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}
    int equalPairs(vector<vector<int>>& grid) {
        int cnt=0;
        unordered_map <int,vector<int>> r;
        unordered_map <int,vector<int>> c;
       for(int i=0;i<grid.size();i++)
            {
                r[i]=(grid[i]);
            }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                c[i].push_back(grid[j][i]);
            }
        }

        for(int i=0;i<r.size();i++)
        {
            for(int j=0;j<c.size();j++)
            {
                if(compareArrays(r[i],c[j])) cnt++;
            }
        }

            return cnt;
    }
};