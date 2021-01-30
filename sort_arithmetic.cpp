#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int size = arr.size();
        int delta = arr[1] - arr[0];
        for (int i = 1; i < size - 1; ++ i)
        {
            if (arr[i + 1] - arr[i] != delta)
            {
                return false;
            }
        }
        return true;
    }
};
