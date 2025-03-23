class Solution {
public:
    const int MOD = 1e9 + 7;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adj(n);
    
    // Build adjacency list
    for (auto& road : roads) {
        adj[road[0]].push_back({road[1], road[2]});
        adj[road[1]].push_back({road[0], road[2]});
    }

    vector<long long> dist(n, LLONG_MAX); // Stores shortest distances
    vector<int> ways(n, 0); // Stores number of ways to reach each node in shortest time
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0}); // {distance, node}

    while (!pq.empty()) {
        auto [curDist, node] = pq.top();
        pq.pop();
        
        if (curDist > dist[node]) continue; // Skip outdated entries
        
        for (auto [neighbor, time] : adj[node]) {
            long long newDist = curDist + time;
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                ways[neighbor] = ways[node]; // Reset ways count
                pq.push({newDist, neighbor});
            } else if (newDist == dist[neighbor]) {
                ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
            }
        }
    }
    
    return ways[n - 1];
}
};