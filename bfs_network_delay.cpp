#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int size = times.size();
        if (!size && n > 0)
        {
            return -1;
        }
        int edges[n + 1][n + 1];
        int been[n + 1];
        for (int i = 1; i <= n; ++ i)
        {
            been[i] = -1;
            for (int j = 1; j <= n; ++ j)
            {
                edges[i][j] = INT_MAX;
            }
        }
        for (int i = 0; i < size; ++ i)
        {
            edges[times[i][0]][times[i][1]] = times[i][2];
        }
        been[k] = 0;
        queue<int> q;
        q.push(k);
        while (!q.empty())
        {
            int size = q.size();
            for (int j = 0; j < size; ++ j)
            {
                int index = q.front();
                q.pop();
                for (int i = 1; i <= n; ++ i)
                {
                    if (i != index && i != k && edges[index][i] != INT_MAX)
                    {
                        if (been[i] == -1)
                        {
                            been[i] = been[index] + edges[index][i];
                            q.push(i);
                        }
                        else
                        {
                            if (been[i] > been[index] + edges[index][i])
                            {
                                been[i] = been[index] + edges[index][i];
                                q.push(i);
                            }
                        }
                    }
                }
            }
        }
        int maxi = INT_MIN;
        for (int i = 1; i <= n; ++ i)
        {
            if (been[i] == -1 && i != k)
            {
                return -1;
            }
            maxi = max(been[i], maxi);
        }
        return maxi;
    }
};
