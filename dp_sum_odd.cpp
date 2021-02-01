#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int size = arr.size();
        int result = 0;
        int dp[size + 1];
        dp[0] = 0;
        dp[1] = arr[0];
        for (int i = 1; i <= size; ++ i)
        {
            dp[i] = dp[i - 1] + arr[i - 1];
        }
        for (int i = 0; i < size; ++ i)
        {
            for (int j = i + 1; j <= size; ++ j)
            {
                if ((j - i)%2)
                {
                    result += (dp[j] - dp[i]);
                }
            }
        }
        return result;
    }
};
