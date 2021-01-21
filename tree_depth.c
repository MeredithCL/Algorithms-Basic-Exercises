#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    long long value;
    long long left;
    long long right;
};
TreeNode xxx[1000010];
long long ans = 0;
void result(long long now, long long cnt)
{
    if (now == 0)
    {
        return;
    }
    cnt ++;
    ans = max(cnt, ans);
    result(xxx[now].left, cnt);
    result(xxx[now].right, cnt);
}
int main()
{
    long long n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        xxx[i].value = i;
        long long x, y;
        cin >> x >> y;
        xxx[i].left = x;
        xxx[i].right = y;
    }
    result(1, 0);
    cout << ans << endl;
    getchar();
    getchar();
    return 0;
}
