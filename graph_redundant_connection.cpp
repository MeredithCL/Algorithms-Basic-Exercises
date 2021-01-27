#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find(int i, int parent[])
    {
        if (parent[i] == i)
        {
            return parent[i];
        }
        parent[i] = find(parent[i], parent);
        return parent[i];
    }
    void unionx(int x, int y, int parent[], int rankt[])
    {
        int a = find(x, parent);
        int b = find(y, parent);
        if (rankt[a] < rankt[b])
        {
            parent[a] = b;
        }
        else if (rankt[b] < rankt[a])
        {
            parent[b] = a;
        }
        else
        {
            parent[a] = b;
            rankt[b] ++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int size = edges.size();
        vector<int> result;
        if (!size)
        {
            return result;
        }
        int parent[size + 1];
        int rankt[size + 1];
        for (int i = 0; i <= size; ++ i)
        {
            parent[i] = i;
            rankt[i] = 0;
        }
        for (int i = 0; i < size; ++ i)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            int a = find(x, parent);
            int b = find(y, parent);
            if (a != b)
            {
                unionx(x, y, parent, rankt);
            }
            else
            {
                result.push_back(x);
                result.push_back(y);
                break;
            }
        }
        return result;
    }
};
