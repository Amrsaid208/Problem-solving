class Solution {
public:
    int ans=0;
    void dfs(int room,vector<vector<int>>& rooms, vector<bool> & vis)
    {
        if(room >= rooms.size() || vis[room]) return;
        vis[room] = 1;
        ans++;
        for(int i= 0;i<rooms[room].size();i++)
        {
            if(!vis[rooms[room][i]])
            dfs(rooms[room][i],rooms,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // vis.resize(rooms.size());
            vector<bool> vis(rooms.size(),0);

        // for(bool  &x : vis) x=false;
        dfs(0,rooms,vis);
      
        return ans == rooms.size();
    }
};