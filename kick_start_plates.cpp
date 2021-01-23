#include <bits/stdc++.h>
using namespace std;
int t, n, k, p;
int beauty[60][35] = {0};
int sumx[60][35] = {0};
int dp[1500][1500] = {0};
int main()
{
    cin >> t;
    for (int u = 0; u < t; ++ u)
    {
        cin >> n >> k >> p;
        for (int i = 1; i <= n; ++ i)
        {
            int resultx = 0;
            for (int j = 1; j <= k; ++ j)
            {
                cin >> beauty[i][j];
                resultx += beauty[i][j];
                sumx[i][j] = resultx;
            }
        }
        for (int i = 1; i <= n; ++ i) // n stacks
        {
            for (int j = 0; j <= p; ++ j) // j plates
            {
                dp[i][j] = 0;
                int boundary = min(j, k);
                for (int m = 0; m <= boundary; ++ m)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - m] + sumx[i][m]);
                }
            }
        }
        cout << "Case #" << u + 1 << ": " << dp[n][p] << endl;
    }
    return 0;
}
