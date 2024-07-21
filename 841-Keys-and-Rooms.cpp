class Solution {
public:
    vector<int> vis;
    int ans=0;
    void dfs(int room,vector<vector<int>>& rooms)
    {
        if(room >= rooms.size() || vis[room]) return;
        vis[room] = 1;
        ans++;
        for(int i= 0;i<rooms[room].size();i++)
        {
            if(!vis[rooms[room][i]])
            dfs(rooms[room][i],rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vis.resize(rooms.size());
        for(auto  &x : vis) x=0;
        dfs(0,rooms);
      
        return ans == rooms.size();
    }
};