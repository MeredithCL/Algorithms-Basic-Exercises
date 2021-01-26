#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int findparent(int parent[], int i)
    {
        if (parent[i] == i)
        {
            return parent[i];
        }
        parent[i] = findparent(parent, parent[i]);
        return parent[i];
    }
    void unionx(int x, int y, int parent[], int rankt[])
    {
        int a = findparent(parent, x);
        int b = findparent(parent, y);
        if (a == b)
        {
            return;
        }
        if (rankt[b] > rankt[a])
        {
            parent[a] = b;
            return;
        }
        else if (rankt[a] > rankt[b])
        {
            parent[b] = a;
            return;
        }
        else
        {
            parent[a] = b;
            rankt[b] ++;
            return;
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        int rankt[4*n*n];
        int parent[4*n*n];
        for (int i = 0; i < 4*n*n; ++ i)
        {
            parent[i] = i;
            rankt[i] = 0;
        }
        int now;
        for (int i = 0; i < n; ++ i)
        {
            for (int j = 0; j < n; ++ j)
            {
                now = (n*i + j)*4;
                char c = grid[i][j];
                if (c == '\\')
                {
                    unionx(now, now + 1, parent, rankt);
                    unionx(now + 2, now + 3, parent, rankt);
                }
                else if (c == '/')
                {
                    unionx(now, now + 3, parent, rankt);
                    unionx(now + 1, now + 2, parent, rankt);
                }
                else if (c == ' ')
                {
                    unionx(now, now + 1, parent, rankt);
                    unionx(now, now + 2, parent, rankt);
                    unionx(now, now + 3, parent, rankt);
                }
                /*     3
                    0     2 
                       1
                */
                if (i + 1 < n)
                {
                    unionx(now + 1, now + 4*n + 3, parent, rankt);
                }
                if (i - 1 >= 0)
                {
                    unionx(now + 3, now - 4*n + 1, parent, rankt);
                }
                if (j + 1 < n)
                {
                    unionx(now + 2, now + 4, parent, rankt);
                }
                if (j - 1 >= 0)
                {
                    unionx(now, now - 2, parent, rankt);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < 4*n*n; ++ i)
        {
            if (parent[i] == i)
            {
                ++ cnt;
            }
        }
        return cnt;
    }
};
