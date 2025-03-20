class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int, int>>> graph(n);
        
        // Build the adjacency list
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        
        
        vector<int> component(n, -1);  
        vector<int> minCost(n, INT_MAX);
        int compId = 0;
        
        for (int i = 0; i < n; i++) {
            if (component[i] != -1) continue;  
            queue<int> q;
            q.push(i);
            component[i] = compId;
            int andValue = INT_MAX;
            
            while (!q.empty()) {
                int node = q.front(); q.pop();
                
                for (auto& [neighbor, weight] : graph[node]) {
                    if (component[neighbor] == -1) {
                        component[neighbor] = compId;
                        q.push(neighbor);
                    }
                    andValue &= weight;
                }
            }
            minCost[compId] = andValue;
            compId++;
        }
        
        
        vector<int> answer;
        for (auto& q : query) {
            int s = q[0], t = q[1];
            if (s == t) {
                answer.push_back(0);
            } else if (component[s] == component[t]) {
                answer.push_back(minCost[component[s]]);
            } else {
                answer.push_back(-1);
            }
        }
        
        return answer;
    }
};