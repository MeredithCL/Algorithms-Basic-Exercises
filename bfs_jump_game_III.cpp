#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int size = arr.size();
        queue<int> q;
        q.push(start);
        int been[size + 1];
        for (int i = 0; i <= size; ++ i)
        {
            been[i] = 0;
        }
        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; ++ i)
            {
                int index = q.front();
                q.pop();
                int value = arr[index];
                been[index] = 1;
                if (!value)
                {
                    return true;
                }
                int x = index + value;
                int y = index - value;
                if (x < size && been[x] == 0)
                {
                    q.push(x);
                }
                if (y >= 0 && been[y] == 0)
                {
                    q.push(y);
                }
            }
        }
        return false;
    }
};
