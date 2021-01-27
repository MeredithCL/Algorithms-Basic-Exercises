#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int i, int color[], vector<vector<int>> &graph)
    {
        if (color[i] > 0)
        {
            return color[i] == 2;
        }
        color[i] = 1;
        int size = graph[i].size();
        for (int j = 0; j < size; ++ j)
        {
            if (color[i] == 2)
            {
                continue;
            }
            if (color[graph[i][j]] == 1 || !dfs(graph[i][j], color, graph))
            {
                return false;
            }
        }
        color[i] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n + 1];
        vector<int> result;
        memset(color, 0, sizeof(color));
        for (int i = 0; i < n; ++ i)
        {
            if (dfs(i, color, graph))
            {
                result.push_back(i);
            }
        }
        return result;
    }
};
