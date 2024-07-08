class TimeMap {
public:
    TimeMap() {
        
    }
     unordered_map<string, map<int, string>> mp;
    void set(string key, string value, int timestamp) {
         mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        // else
        string ans="";
        for (auto it = mp[key].rbegin(); it != mp[key].rend(); it++) {
                if(it->first <= timestamp) {
                    ans = it->second;
                    break;
                }
            }
        return ans;
       
    }
};
/***
fooo bar 1  

*/
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */