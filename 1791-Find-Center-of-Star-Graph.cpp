class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=0;
        for(auto x:edges)
        {
            n=max(n,max(x[0],x[1]));
        }
        vector<vector<int>>adjMat(n+1);
        for(auto x:edges)
        {
            adjMat[x[0]].push_back(x[1]);
            adjMat[x[1]].push_back(x[0]);

        }
        int ans=0;
        int mx=0;
        for(int i=0;i<adjMat.size();i++)
        {
            auto x=adjMat[i];
            if(x.size() > mx) {
                mx=x.size();
                ans=i;
            }
        }
        return ans;
    }
};