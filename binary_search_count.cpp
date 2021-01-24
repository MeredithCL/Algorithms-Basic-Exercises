#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        int cnt = 0;
        int size = grid.size();
        if (!size)
        {
            return result;
        }
        int size1 = grid[0].size();
        for (int i = 0; i < size; ++ i)
        {
            cnt = 0;
            if (size1 == 1 && grid[i][0] < 0)
            {
                cnt ++;
                result += cnt;
            }
            else
            {
                cnt = size1;
                int in = 0;
                int ax = size1 - 1;
                while (in <= ax)
                {
                    int middle = (in + ax) / 2;
                    if (grid[i][middle] >= 0)
                    {
                        in = middle + 1;
                    }
                    if (grid[i][middle] < 0)
                    {
                        cnt = middle;
                        ax = middle - 1;
                    }
                }
                result += (size1 - cnt);
            }
        }
        return result;
    }
};
