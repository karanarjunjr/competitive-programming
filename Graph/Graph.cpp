class Graph {
public:
    vector<vector<int>> adj;
    vector<int> vis, in, out, sssp, color, parent, subTree;
    int timer = 1;

    Graph() {
        adj.resize(10000 + 1);
        vis.resize(10000 + 1, 0);
        in.resize(10000 + 1, 0);
        out.resize(10000 + 1, 0);
        sssp.resize(10000 + 1, -1);
        color.resize(10000 + 1);
        parent.resize(10000 + 1, 0);
        subTree.resize(10000 + 1, 0);
    }

    Graph(int n) {
        adj.resize(n + 1);
        vis.resize(n + 1, 0);
        in.resize(n + 1, 0);
        out.resize(n + 1, 0);
        sssp.resize(n + 1, -1);
        color.resize(n + 1);
        parent.resize(n + 1, 0);
        subTree.resize(n + 1, 0);
    }

    void clearG() {
        for (int i = 0; i < 100001; i++) {
            adj[i].clear();
        }
    }

    void clearVis() {
        for (int i = 1; i <= 100000; i++) {
            vis[i] = 0;
        }
    }

    void dfs(int v, int par) {
        vis[v] = 1;
        parent[v] = par;
        in[v] = timer++;
        for (auto child : adj[v]) {
            if (!vis[child])
                dfs(child, v);
        }
        out[v] = timer++;
    }

    void bfs(int v) {
        vis[v] = 1;

        queue<int> q;
        q.push(v);
        // cout << v << " ";
        sssp[v] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto child : adj[cur]) {
                if (!vis[child]) {
                    vis[child] = 1;
                    sssp[child] = sssp[cur] + 1;
                    q.push(child);
                    // cout << child << " ";
                }
            }
        }
    }

    int connectedComponents(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                ans++;
                int edges = 0;
                int nodes = 0;
                dfs(i, 0);
            }
        }

        return ans;
    }

    void SSSP_tree(int v) {
        vis[v] = 1;

        for (auto child : adj[v]) {
            if (!vis[child]) {
                sssp[child] = sssp[v] + 1;
                SSSP_tree(child);
            }
        }
    }

    bool isBipartite(int v, int c) {
        vis[v] = 1;
        color[v] = c;

        for (auto child : adj[v]) {
            if (vis[child] == 0) {
                if (!isBipartite(child, c ^ 1))
                    return false;
            } else if (color[v] == color[child]) {
                return false;
            }
        }

        return true;
    }

    bool hasCycle(int v, int par) {
        clearVis();

        vis[v] = 1;

        for (auto child : adj[v]) {
            if (!vis[child]) {
                if (hasCycle(child, v))
                    return true;
            } else {
                if (child != par) {
                    return true;
                }
            }
        }
        return false;
    }

    int subTreeSize(int v) {
        vis[v] = 1;
        int curSize = 1;

        for (auto child : adj[v]) {
            if (!vis[child]) {
                curSize += subTreeSize(child);
            }
        }

        subTree[v] = curSize;
        return curSize;
    }
};
