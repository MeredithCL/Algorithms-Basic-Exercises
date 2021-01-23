#include <bits/stdc++.h>
using namespace std;
int t, n;
string str;
int maxi = 0;
int cnt = 0;
int main()
{
    cin >> t;
    for (int u = 0; u < t; ++ u)
    {
        cin >> n;
        cin >> str;
        maxi = 0;
        cnt ++;
        int k = ceil(n / 2);
        if (n % 2)
        {
            ++ k;
        }
        int result = 0;
        for (int i = 0; i < k; ++ i)
        {
            result += str[i] - '0';
        }
        maxi = max(result, maxi);
        for (int i = 1; i <= n - k; ++ i)
        {
            result -= (str[i - 1] - '0');
            result += (str[i + k - 1] - '0');
            maxi = max(result, maxi);
        }
        cout << "Case #" << cnt << ": " << maxi << endl;
    }
    getchar();
    getchar();
    return 0;
}
