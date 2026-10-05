class Solution {
public:
    void dfs(string src , unordered_map<string , vector<string>>& adj , vector<string>& ans){
        while(!adj[src].empty()){
            string next = adj[src].back();
            adj[src].pop_back();

            dfs(next , adj ,ans);
        }

        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //building the adj list
        unordered_map<string , vector<string>> adj;
        for(auto t : tickets){
            string from = t[0];
            string to = t[1];
            adj[from].push_back(to);
        }

        vector<string> ans;
        //sort for lexicographical ordder
        for(auto &[from,to] : adj){
            sort(to.rbegin() , to.rend());
        }

        dfs("JFK" , adj , ans);
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
