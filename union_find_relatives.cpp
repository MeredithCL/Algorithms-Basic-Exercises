#include <bits/stdc++.h>
using namespace std;
int n, m, p;
int parent[5010] = {0};
int rankx[5010] = {0};
int find(int parent[], int i)
{
    if (parent[i] == i)
    {
        return parent[i];
    }
    parent[i] = find(parent, parent[i]);
    return parent[i];
}
void unionx(int parent[], int rank[], int x, int y)
{
    int a = find(parent, x);
    int b = find(parent, y);
    if (rankx[b] > rankx[a])
    {
        parent[a] = b;
    }
    else if (rankx[a] > rankx[b])
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
        rankx[b] ++;
    }
}
int main()
{
    cin >> n >> m >> p;
    int x, y;
    for (int i = 0; i <= n; i ++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < m; ++ i)
    {
        cin >> x >> y;
        unionx(parent, rankx, x, y);
    }
    int a, b;
    for (int i = 0; i < p; ++ i)
    {
        cin >> x >> y;
        a = find(parent, x);
        b = find(parent, y);
        if (a == b)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    getchar();
    getchar();
    return 0;
}