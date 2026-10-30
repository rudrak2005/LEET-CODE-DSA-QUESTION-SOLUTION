class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        using State = tuple<long long, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;
        vector<vector<long long>> min_cost(n, vector<long long>(k + 1, LLONG_MAX));

        pq.push({0, 0, 1});
        min_cost[0][1] = 0;

        while (!pq.empty()) {
            auto [cost, u, run] = pq.top();
            pq.pop();

            if (u == n - 1) {
                return (int)cost;
            }

            if (cost > min_cost[u][run]) continue;

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                int next_run = (labels[u] == labels[v]) ? run + 1 : 1;

                if (next_run > k) continue;

                long long next_cost = cost + w;

                if (next_cost < min_cost[v][next_run]) {
                    min_cost[v][next_run] = next_cost;
                    pq.push({next_cost, v, next_run});
                }
            }
        }

        return -1;
    }
};